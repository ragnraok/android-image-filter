package cn.Ragnarok;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;

public class RagnarokFilterActivity extends Activity implements OnClickListener {
    /** Called when the activity is first created. */
	
	ImageView imageView;
	Button grayButton;
	Button vagueButton;
	Button reliefButton;
	Button oilButton;
	Button neonButton;
	Button pixelateButton;
	Button invertButton;
	Button tvButton;
	Button blockkButton;
	Button oldButton;
	Button sharpenButton;
	Button lightButton;
	Button sourceButton;
	
	Bitmap sourceBitmap;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        imageView = (ImageView) findViewById(R.id.image);
        sourceBitmap = BitmapFactory.decodeResource(this.getResources(), R.drawable.test);
        
        grayButton = (Button) findViewById(R.id.button_change_to_gray);
        vagueButton = (Button) findViewById(R.id.button_change_to_vague);
        reliefButton = (Button) findViewById(R.id.button_change_to_relief);
        oilButton = (Button) findViewById(R.id.button_change_to_oid);
        neonButton = (Button) findViewById(R.id.button_change_to_neon);
        pixelateButton = (Button) findViewById(R.id.button_change_to_pixelate);
        invertButton = (Button) findViewById(R.id.button_change_to_invert);
        tvButton = (Button) findViewById(R.id.button_change_to_tv);
        blockkButton = (Button) findViewById(R.id.button_change_to_block);
        oldButton = (Button) findViewById(R.id.button_change_to_old);
        sharpenButton = (Button) findViewById(R.id.button_change_to_sharpen);
        lightButton = (Button) findViewById(R.id.button_change_to_light);
        sourceButton = (Button) findViewById(R.id.button_change_to_source);
        
        grayButton.setOnClickListener(this);
        vagueButton.setOnClickListener(this);
        reliefButton.setOnClickListener(this);
        oilButton.setOnClickListener(this);
        neonButton.setOnClickListener(this);
        pixelateButton.setOnClickListener(this);
        invertButton.setOnClickListener(this);
        tvButton.setOnClickListener(this);
        blockkButton.setOnClickListener(this);
        oldButton.setOnClickListener(this);
        sharpenButton.setOnClickListener(this);
        lightButton.setOnClickListener(this);
        sourceButton.setOnClickListener(this);
        
        
    }

	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		
		switch (v.getId())
		{
		case R.id.button_change_to_gray:
			Bitmap gray = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.GRAY_STYLE);
			imageView.setImageBitmap(gray);
			break;
		case R.id.button_change_to_oid:
			Bitmap oil = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.OIL_STYLE);
			imageView.setImageBitmap(oil);
			break;
		case R.id.button_change_to_relief:
			Bitmap relief = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.RELIEF_STYLE);
			imageView.setImageBitmap(relief);
			break;
		case R.id.button_change_to_vague:
			Bitmap vague = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.VAGUE_STYLE);
			imageView.setImageBitmap(vague);
			break;
		case R.id.button_change_to_neon:
			Bitmap neon = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.NEON_STYLE);
			imageView.setImageBitmap(neon);
			break;
		case R.id.button_change_to_pixelate:
			Bitmap pixelate = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.PIXELATE_STYLE);
			imageView.setImageBitmap(pixelate);
			break;
		case R.id.button_change_to_invert:
			Bitmap invert = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.INVERT_STYLE);
			imageView.setImageBitmap(invert);
			break;
		case R.id.button_change_to_tv:
			Bitmap tv = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.TV_STYLE);
			imageView.setImageBitmap(tv);
			break;
		case R.id.button_change_to_block:
			Bitmap brick = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.BLOCK_STYLE);
			imageView.setImageBitmap(brick);
			break;
		case R.id.button_change_to_old:
			Bitmap old = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.OLD_STYLE);
			imageView.setImageBitmap(old);
			break;
		case R.id.button_change_to_sharpen:
			Bitmap sharpen = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.SHARPEN_STYLE);
			imageView.setImageBitmap(sharpen);
			break;
		case R.id.button_change_to_light:
			Bitmap light = BitmapFilter.changeStyle(sourceBitmap, BitmapFilter.LIGHT_STYLE);
			imageView.setImageBitmap(light);
			break;
		case R.id.button_change_to_source:
			imageView.setImageBitmap(sourceBitmap);
			break;
		}
	}
}