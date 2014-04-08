package cn.Ragnarok;

import java.util.Random;

import android.R.style;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.ColorMatrix;
import android.graphics.ColorMatrixColorFilter;
import android.graphics.Paint;

/**
 * 滤镜效果的类，定义了基本的渲染方法
 * @author ragnarok
 *
 */
public class BitmapFilter {
	/**
	 * 所有滤镜效果的id
	 */
	public static final int GRAY_STYLE = 1; // gray scale
	public static final int RELIEF_STYLE = 2; // relief
	public static final int BLUR_STYLE = 3; // average blur
	public static final int OIL_STYLE = 4; // oil painting
	public static final int NEON_STYLE = 5; // neon
	public static final int PIXELATE_STYLE = 6; // pixelate
	public static final int TV_STYLE = 7; // Old TV
	public static final int INVERT_STYLE = 8; // invert the colors
	public static final int BLOCK_STYLE = 9; // engraving
	public static final int OLD_STYLE = 10; // old photo
	public static final int SHARPEN_STYLE = 11; // sharpen
	public static final int LIGHT_STYLE = 12; // light
	public static final int LOMO_STYLE = 13; // lomo
	public static final int HDR_STYLE = 14; // HDR
	public static final int GAUSSIAN_BLUR_STYLE = 15; // gaussian blur
	public static final int SOFT_GLOW_STYLE = 16; // soft glow
	public static final int SKETCH_STYLE = 17; // sketch style
	
	public static final int TOTAL_FILTER_NUM = 17;
	
	/**
	 * change bitmap filter style
	 * @param bitmap
	 * @param styeNo, 效果id
	 */
	public static Bitmap changeStyle(Bitmap bitmap, int styleNo) {
		if (styleNo == GRAY_STYLE) {
			//return changeToGray(bitmap);
			return GrayFilter.changeToGray(bitmap);
		}
		else if (styleNo == RELIEF_STYLE) {
			return ReliefFilter.changeToRelief(bitmap);
		}
		else if (styleNo == BLUR_STYLE) {
			return BlurFilter.changeToVague(bitmap);
		}
		else if (styleNo == OIL_STYLE) {
			return OilFilter.changeToOil(bitmap);
		}
		else if (styleNo == NEON_STYLE) {
			return NeonFilter.changeToNeon(bitmap);
		}
		else if (styleNo == PIXELATE_STYLE) {
			return PixelateFilter.changeToPixelate(bitmap);
		}			
		else if (styleNo == TV_STYLE) {
			return TvFilter.changeToTV(bitmap);
		}
		else if (styleNo == INVERT_STYLE) {
			return InvertFilter.chageToInvert(bitmap);
		}
		else if (styleNo == BLOCK_STYLE) {
			return BlockFilter.changeToBrick(bitmap);
		}
		else if (styleNo == OLD_STYLE) {
			return OldFilter.changeToOld(bitmap);
		}
		else if (styleNo == SHARPEN_STYLE) {
			return SharpenFilter.changeToSharpen(bitmap);
		}
		else if (styleNo == LIGHT_STYLE) {
			return LightFilter.changeToLight(bitmap);
		}
		else if (styleNo == LOMO_STYLE) {
			return LomoFilter.changeToLomo(bitmap);
		}
		else if (styleNo == HDR_STYLE) {
			return HDRFilter.changeToHDR(bitmap);
		}
		else if (styleNo == GAUSSIAN_BLUR_STYLE) {
			return GaussianBlurFilter.changeToGaussianBlur(bitmap);
		}
		else if (styleNo == SOFT_GLOW_STYLE) {
			return SoftGlowFilter.softGlowFilter(bitmap);
		}
		else if (styleNo == SKETCH_STYLE) {
			return SketchFilter.changeToSketch(bitmap);
		}
		return bitmap;
	}
	
	

}

















