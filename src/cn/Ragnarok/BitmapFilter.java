package cn.Ragnarok;

import java.util.Random;

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
	public static final int GRAY_STYLE = 1; // 黑白效果
	public static final int RELIEF_STYLE = 2; // 浮雕效果
	public static final int VAGUE_STYLE = 3; // 模糊效果
	public static final int OIL_STYLE = 4; // 油画效果
	public static final int NEON_STYLE = 5; // 霓虹灯效果
	public static final int PIXELATE_STYLE = 6; // 像素化效果
	public static final int TV_STYLE = 7; // TV效果
	public static final int INVERT_STYLE = 8; // 反色效果
	public static final int BLOCK_STYLE = 9; // 版画
	public static final int OLD_STYLE = 10; // 怀旧效果
	public static final int SHARPEN_STYLE = 11; // 锐化效果
	public static final int LIGHT_STYLE = 12; // 光照效果
	
	/**
	 * 设置滤镜效果，
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
		else if (styleNo == VAGUE_STYLE) {
			return VagueFilter.changeToVague(bitmap);
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
			return bitmap;
	}
	
	

}

















