package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.Paint;
import android.util.Log;

public class NeonFilter {
	
	static {
		System.loadLibrary("AndroidImageFilter");
	}
	
	// 霓虹灯效果函数
	public static Bitmap changeToNeon(Bitmap bitmap) {
		int width = bitmap.getWidth();
		int height = bitmap.getHeight();
		
		Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);
		int[] pixels = new int[width * height];
		bitmap.getPixels(pixels, 0, width, 0, 0, width, height);
		
		int[] returnPixels = NativeFilterFunc.neonFilter(pixels, width, height);
		Log.d("AndroidImageFilter", "returnPixles[1] = " + returnPixels[1]);
		returnBitmap.setPixels(returnPixels, 0, width, 0, 0, width, height);
		
		return returnBitmap;
	}
	/*
	public static Bitmap changeToNeon(Bitmap bitmap) {

		int width = bitmap.getWidth();
		int height = bitmap.getHeight();

		Bitmap returnBitmap = Bitmap.createBitmap(width, height,
				Bitmap.Config.RGB_565);

		int colorArray[] = new int[width * height];
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

		Paint grayMatrix[] = new Paint[256];

		// Init gray matrix
		int outlineCase = 1;
		double rand = Math.random();
		if (rand > 0.33 && rand < 0.66) {
			outlineCase = 2;
		} else if (rand > 0.66) {
			outlineCase = 3;
		}
		for (int i = 255; i >= 0; i--) {
			Paint p = new Paint();
			int red = i, green = i, blue = i;
			if (i > 127) {
				switch (outlineCase) {
				case 1:
					red = 255 - i;
					break;

				case 2:
					green = 255 - i;
					break;

				case 3:
					blue = 255 - i;
					break;
				}
			}
			p.setColor(Color.rgb(red, green, blue));
			grayMatrix[255 - i] = p;
		}

		int[][] luminance = new int[width][height];
		for (int y = 0; y < height; y++) {
			for (int x = 0; x < width; x++) {
				luminance[x][y] = (int) luminance(
						(colorArray[((y * width + x))] & 0x00FF0000) >> 16,
						(colorArray[((y * width + x))] & 0x0000FF00) >> 8,
						colorArray[((y * width + x))] & 0x000000FF);
			}
		}

		int grayX, grayY;
		int magnitude;
		for (int y = 1; y < height - 1; y++) {
			for (int x = 1; x < width - 1; x++) {
				// sobel
				grayX = -luminance[x - 1][y - 1] + luminance[x - 1][y - 1 + 2]
						- 2 * luminance[x - 1 + 1][y - 1] + 2
						* luminance[x - 1 + 1][y - 1 + 2]
						- luminance[x - 1 + 2][y - 1]
						+ luminance[x - 1 + 2][y - 1 + 2];

				grayY = luminance[x - 1][y - 1] + 2
						* luminance[x - 1][y - 1 + 1]
						+ luminance[x - 1][y - 1 + 2]
						- luminance[x - 1 + 2][y - 1] - 2
						* luminance[x - 1 + 2][y - 1 + 1]
						- luminance[x - 1 + 2][y - 1 + 2];

				// Magnitudes sum
				magnitude = 255 - truncate(Math.abs(grayX) + Math.abs(grayY));
				Paint grayscaleColor = grayMatrix[magnitude];

				// Apply the color into a new image
				returnBitmap.setPixel(x, y, grayscaleColor.getColor());
			}
		}

		return returnBitmap;
	}

	// calculate gray scale
	private static int luminance(int r, int g, int b) {
		return (int) ((0.299 * r) + (0.58 * g) + (0.11 * b));
	}


	private static int truncate(int a) {
		if (a < 0)
			return 0;
		else if (a > 255)
			return 255;
		else
			return a;
	}*/
}
