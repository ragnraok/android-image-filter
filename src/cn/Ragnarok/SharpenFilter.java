package cn.Ragnarok;

import java.util.Arrays;

import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.ColorMatrix;

public class SharpenFilter {
	

	public static Bitmap changeToSharpen(Bitmap bitmap) {

		int laplacian[] = {  0, -1, 0, -1, 4, -1, 0, -1, 0 };  
          
        int width = bitmap.getWidth();  
        int height = bitmap.getHeight();  
        Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.ARGB_8888);  
          
        int pixR = 0;  
        int pixG = 0;  
        int pixB = 0;  
          
        int pixColor = 0;  
          
        int newR = 0;  
        int newG = 0;  
        int newB = 0;
          
        int idx = 0; 
        int[] pixels = new int[width * height];
        int[] tempPixels = new int[width * height];
        Arrays.fill(tempPixels, 0);
        
        bitmap.getPixels(pixels, 0, width, 0, 0, width, height);  
        
        for (int i = 1; i < height - 1; i++)  // y
        {  
            for (int k = 1; k < width - 1; k++)  // x
            {
                idx = 0;
                newR = newG = newB = 0;
                for (int m = -1; m <= 1; m++)  
                {  
                    for (int n = -1; n <= 1; n++)  
                    {  
                        pixColor = pixels[(i + n) * width + k + m];  
                        pixR = Color.red(pixColor);  
                        pixG = Color.green(pixColor);  
                        pixB = Color.blue(pixColor);  
                          
                        newR += (int) (pixR * laplacian[idx]);  
                        newG += (int) (pixG * laplacian[idx]);  
                        newB += (int) (pixB * laplacian[idx]);  
                        idx++;  
                    }  
                }  
                  
                newR = Math.min(255, Math.max(0, newR));  
                newG = Math.min(255, Math.max(0, newG));  
                newB = Math.min(255, Math.max(0, newB));  
                  
                tempPixels[i * width + k] = Color.rgb(newR, newG, newB);
                newR = newG = newB = 0;
                 
            }  
        }
        
        for (int i = 0; i < width * height; i++) {
        	int r = Color.red(tempPixels[i]);
        	int g = Color.green(tempPixels[i]);
        	int b = Color.blue(tempPixels[i]);
        	
        	int nR = Color.red(pixels[i]);
        	int nG = Color.green(pixels[i]);
        	int nB = Color.blue(pixels[i]);
        	
        	pixels[i] = Color.rgb(Math.min(255, Math.max(0, nR + r))	, Math.min(255, Math.max(0, nG + g)), 
        			Math.min(255, Math.max(0, nB + b)));
        }
        
        returnBitmap.setPixels(pixels, 0, width, 0, 0, width, height);
        
        return returnBitmap;
	}
}
