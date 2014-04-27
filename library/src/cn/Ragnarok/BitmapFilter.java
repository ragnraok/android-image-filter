package cn.Ragnarok;

import android.R.style;
import android.graphics.Bitmap;

public class BitmapFilter {
	/**
	 * filter style id;
	 */
	public static final int GRAY_STYLE = 1; // gray scale
	public static final int RELIEF_STYLE = 2; // relief
	public static final int AVERAGE_BLUR_STYLE = 3; // average blur
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
	public static final int MOTION_BLUR_STYLE = 18; // motion blur
	public static final int GOTHAM_STYLE = 19; // gotham style
	
	public static final int TOTAL_FILTER_NUM = GOTHAM_STYLE;
	
	/**
	 * change bitmap filter style
	 * @param bitmap
	 * @param styeNo, filter sytle id
	 */
	public static Bitmap changeStyle(Bitmap bitmap, int styleNo, Object... options) {
		if (styleNo == GRAY_STYLE) {
			return GrayFilter.changeToGray(bitmap);
		}
		else if (styleNo == RELIEF_STYLE) {
			return ReliefFilter.changeToRelief(bitmap);
		}
		else if (styleNo == AVERAGE_BLUR_STYLE) {
			if (options.length < 1) {
				return BlurFilter.changeToAverageBlur(bitmap, 5);
			}
			return BlurFilter.changeToAverageBlur(bitmap, (Integer)options[0]); // maskSize
		}
		else if (styleNo == OIL_STYLE) {
			if (options.length < 1) {
				return OilFilter.changeToOil(bitmap, 5);
			}
			return OilFilter.changeToOil(bitmap, (Integer)options[0]);
		}
		else if (styleNo == NEON_STYLE) {
			if (options.length < 3) {
				return NeonFilter.changeToNeon(bitmap, 200, 50, 100);
			}
			return NeonFilter.changeToNeon(bitmap, (Integer)options[0], (Integer)options[1], (Integer)options[2]);
		}
		else if (styleNo == PIXELATE_STYLE) {
			if (options.length < 1) {
				return PixelateFilter.changeToPixelate(bitmap, 10);
			}
			return PixelateFilter.changeToPixelate(bitmap, (Integer)options[0]);
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
			if (options.length < 3) {
				int width = bitmap.getWidth();
				int height = bitmap.getHeight();
				return LightFilter.changeToLight(bitmap, width / 2, height / 2, Math.min(width / 2, height / 2));
			}
			return LightFilter.changeToLight(bitmap, (Integer)options[0], 
					(Integer)options[1], (Integer)options[2]); // centerX, centerY, radius
		}
		else if (styleNo == LOMO_STYLE) {
			if (options.length < 1) {
				double radius = (bitmap.getWidth() / 2) * 95 / 100;
				return LomoFilter.changeToLomo(bitmap, radius);
			}
			return LomoFilter.changeToLomo(bitmap, (Double)options[0]);
		}
		else if (styleNo == HDR_STYLE) {
			return HDRFilter.changeToHDR(bitmap);
		}
		else if (styleNo == GAUSSIAN_BLUR_STYLE) {
			if (options.length < 1) {
				return GaussianBlurFilter.changeToGaussianBlur(bitmap, 1.2);
			}
			return GaussianBlurFilter.changeToGaussianBlur(bitmap, (Double)options[0]); // sigma
		}
		else if (styleNo == SOFT_GLOW_STYLE) {
			if (options.length < 1) {
				return SoftGlowFilter.softGlowFilter(bitmap, 0.6);
			}
			return SoftGlowFilter.softGlowFilter(bitmap, (Double)options[0]);
		}
		else if (styleNo == SKETCH_STYLE) {
			return SketchFilter.changeToSketch(bitmap);
		} 
		else if (styleNo == MOTION_BLUR_STYLE) {
			if (options.length < 2) {
				return MotionBlurFilter.changeToMotionBlur(bitmap, 5, 1);
			}
			return MotionBlurFilter.changeToMotionBlur(bitmap, (Integer)options[0], (Integer)options[1]);
		}
		else if (styleNo == GOTHAM_STYLE) {
			return GothamFilter.changeToGotham(bitmap);
		}
		return bitmap;
	}

}