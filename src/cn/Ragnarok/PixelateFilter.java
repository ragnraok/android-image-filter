package cn.Ragnarok;

import android.graphics.Bitmap;

public class PixelateFilter {
	private static int pixelSize = 16;
	private static int colorArray[];
	private static int width;
	private static int height;
	
	// 像素化效果函数
	public static final Bitmap changeToPixelate(Bitmap bitmap) {
		int l_rgb;
		width = bitmap.getWidth();
		height = bitmap.getHeight();
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.RGB_565);
		
		colorArray = new int[width * height];
		int r, g, b;
		bitmap.getPixels(colorArray, 0, width, 0, 0, width, height);
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				int index = y * width + x;
				r = (colorArray[index] >> 16) & 0xff;
				g = (colorArray[index] >> 8) & 0xff;
				b = colorArray[index] & 0xff;
				colorArray[index] = 0xff000000 | (r << 16) | (g << 8) | b;
			}
		}
		
		for (int x = 0; x < width; x+= pixelSize) {
			for (int y = 0; y < bitmap.getHeight(); y+=pixelSize) {				
				l_rgb = getPredominantRGB(bitmap, x,y,pixelSize);
				fillRect(returnBitmap, x,y,pixelSize, l_rgb);					
			}
		}
		
		return returnBitmap;
	}
	
	/**
	 * @return the pixelSize
	 */
	public int getPixelSize() {
		return pixelSize;
	}



	/**
	 * @param pixelSize the pixelSize to set
	 */
	public void setPixelSize(int pixelSize) {
		this.pixelSize = pixelSize;
	}



	/**
	 * Method gets the predominant colour pixels to extrapolate
	 * the pixelation from
	 * 
	 * @param imageIn
	 * @param a_x
	 * @param a_y
	 * @param squareSize
	 * @return
	 */
	private static int getPredominantRGB(Bitmap imageIn, int a_x, int a_y, int squareSize){
		int red=-1;
		int green=-1;
		int blue=-1;
		
		for(int x=a_x; x<a_x+squareSize; x++){
			for(int y=a_y; y<a_y+squareSize; y++){
				if(x < imageIn.getWidth() && y < imageIn.getHeight()){
					
					if(red == -1){
						red = (colorArray[((y*width+x))]& 0x00FF0000) >>> 16;
					}
					else{
						red = ((colorArray[((y*width+x))]& 0x00FF0000) >>> 16)/2;
					}
					if(green == -1){
						green = (colorArray[((y*width+x))]& 0x0000FF00) >>> 8;
					}
					else{
						green = ((colorArray[((y*width+x))]& 0x0000FF00) >>> 8)/2;
					}
					if(blue == -1){
						blue = (colorArray[((y*width+x))] & 0x000000FF);
					}
					else{
						blue = ((colorArray[((y*width+x))] & 0x000000FF))/2;	
					}
				}				
			} 
		}
		return (255<<24)+(red<<16)+(green<<8)+blue;
	}
	
	/**
	 * Method to extrapolate out
	 * 
	 * @param imageIn
	 * @param a_x
	 * @param a_y
	 * @param squareSize
	 * @param a_rgb
	 */
	private static void fillRect(Bitmap imageIn, int a_x, int a_y, int squareSize, int a_rgb){
		for(int x=a_x; x<a_x+squareSize; x++){
			for(int y=a_y; y<a_y+squareSize; y++){
				if(x < imageIn.getWidth() && y < imageIn.getHeight()){
					imageIn.setPixel(x,y,a_rgb);
				}
			}
		}					
	}
}
