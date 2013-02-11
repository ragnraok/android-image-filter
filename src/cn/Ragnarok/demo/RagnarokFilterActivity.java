package cn.Ragnarok.demo;

import cn.Ragnarok.BitmapFilter;
import cn.Ragnarok.LomoFilter;
import cn.Ragnarok.R;
import cn.Ragnarok.R.drawable;
import cn.Ragnarok.R.id;
import cn.Ragnarok.R.layout;
import android.app.Activity;
import android.app.ProgressDialog;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
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
	Button lomoButton;
	Button hdrButton;
	Button sourceButton;
	
	Bitmap sourceBitmap;
	Bitmap change;
	
	Handler handler;
	
	ProgressDialog progressDialog = null;
	
	int styleId = 0;
	
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
        lomoButton = (Button) findViewById(R.id.button_change_to_lomo);
        hdrButton = (Button) findViewById(R.id.button_change_to_hdr);
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
        lomoButton.setOnClickListener(this);
        hdrButton.setOnClickListener(this);
        sourceButton.setOnClickListener(this);
        
        
    }

	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		styleId = 0;
		int id = v.getId();
		if (id == R.id.button_change_to_gray) {
			styleId = BitmapFilter.GRAY_STYLE;
		} else if (id == R.id.button_change_to_oid) {
			styleId = BitmapFilter.OIL_STYLE;
		} else if (id == R.id.button_change_to_relief) {
			styleId = BitmapFilter.RELIEF_STYLE;
		} else if (id == R.id.button_change_to_vague) {
			styleId = BitmapFilter.BLUR_STYLE;
		} else if (id == R.id.button_change_to_neon) {
			styleId = BitmapFilter.NEON_STYLE;
		} else if (id == R.id.button_change_to_pixelate) {
			styleId = BitmapFilter.PIXELATE_STYLE;
		} else if (id == R.id.button_change_to_invert) {
			styleId = BitmapFilter.INVERT_STYLE;
		} else if (id == R.id.button_change_to_tv) {
			styleId = BitmapFilter.TV_STYLE;
		} else if (id == R.id.button_change_to_block) {
			styleId = BitmapFilter.BLOCK_STYLE;
		} else if (id == R.id.button_change_to_old) {
			styleId = BitmapFilter.OLD_STYLE;
		} else if (id == R.id.button_change_to_sharpen) {
			styleId = BitmapFilter.SHARPEN_STYLE;
		} else if (id == R.id.button_change_to_light) {
			styleId = BitmapFilter.LIGHT_STYLE;
		} else if (id == R.id.button_change_to_lomo) {
			styleId = BitmapFilter.LOMO_STYLE;
		} else if (id == R.id.button_change_to_hdr) {
			styleId = BitmapFilter.HDR_STYLE;
		} else if (id == R.id.button_change_to_source) {
			imageView.setImageBitmap(sourceBitmap);
		}
		
		progressDialog = ProgressDialog.show(this, "请稍后", "正在处理中...");
		new Thread() {

			@Override
			public void run() {
				// TODO Auto-generated method stub
				super.run();
				change = BitmapFilter.changeStyle(sourceBitmap, styleId);
				Message msg = Message.obtain();
				msg.what = 1;
				handler.sendMessage(msg);
			}
			
		}.start();
		
		handler = new Handler() {

			@Override
			public void handleMessage(Message msg) {
				// TODO Auto-generated method stub
				super.handleMessage(msg);
				imageView.setImageBitmap(change);
				progressDialog.dismiss();
			}
			
		};
		
	}
}