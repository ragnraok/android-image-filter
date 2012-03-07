package cn.Ragnarok;

import android.graphics.Bitmap;
import android.graphics.Color;
import android.graphics.ColorMatrix;

public class SharpenFilter {
	
	// 锐化效果函数
	public static Bitmap changeToSharpen(Bitmap bitmap) {
		// 拉普拉斯矩阵  
        int[] laplacian = new int[] { -1, -1, -1, -1, 9, -1, -1, -1, -1 };  
          
        int width = bitmap.getWidth();  
        int height = bitmap.getHeight();  
        Bitmap returnBitmap = Bitmap.createBitmap(width, height, Bitmap.Config.RGB_565);  
          
        int pixR = 0;  
        int pixG = 0;  
        int pixB = 0;  
          
        int pixColor = 0;  
          
        int newR = 0;  
        int newG = 0;  
        int newB = 0;  
          
        int idx = 0;  
        float alpha = 0.3F;  
        int[] pixels = new int[width * height];  
        bitmap.getPixels(pixels, 0, width, 0, 0, width, height);  
        for (int i = 1, length = height - 1; i < length; i++)  // y
        {  
            for (int k = 1, len = width - 1; k < len; k++)  // x
            {  
                idx = 0;  
                for (int m = -1; m <= 1; m++)  
                {  
                    for (int n = -1; n <= 1; n++)  
                    {  
                        pixColor = pixels[(i + n) * width + k + m];  
                        pixR = Color.red(pixColor);  
                        pixG = Color.green(pixColor);  
                        pixB = Color.blue(pixColor);  
                          
                        newR = newR + (int) (pixR * laplacian[idx] * alpha);  
                        newG = newG + (int) (pixG * laplacian[idx] * alpha);  
                        newB = newB + (int) (pixB * laplacian[idx] * alpha);  
                        idx++;  
                    }  
                }  
                  
                newR = Math.min(255, Math.max(0, newR));  
                newG = Math.min(255, Math.max(0, newG));  
                newB = Math.min(255, Math.max(0, newB));  
                  
                pixels[i * width + k] = Color.argb(255, newR, newG, newB);  
                newR = 0;  
                newG = 0;  
                newB = 0;  
            }  
        }  
        
        returnBitmap.setPixels(pixels, 0, width, 0, 0, width, height);
        
        return returnBitmap;
	}
}
