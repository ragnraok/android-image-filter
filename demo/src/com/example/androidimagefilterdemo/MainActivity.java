package com.example.androidimagefilterdemo;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;

import android.app.ActionBar;
import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.Intent;
import android.content.res.Configuration;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.provider.MediaStore;
import android.provider.SyncStateContract.Constants;
import android.support.v4.app.ActionBarDrawerToggle;
import android.support.v4.view.GravityCompat;
import android.support.v4.widget.DrawerLayout;
import android.support.v4.widget.DrawerLayout.DrawerListener;
import android.view.Gravity;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.Toast;
import android.widget.RelativeLayout.LayoutParams;
import android.widget.TextView;
import cn.Ragnarok.BitmapFilter;

public class MainActivity extends Activity implements OnClickListener, OnItemClickListener {
	
	private ListView listView;
	private Button changeStyleButton;
	private Button restoreButton;
	private ImageView imageView;
	private LinearLayout imageInfoLayout;
	private TextView imageWidthTextView;
	private TextView imageHeightTextView;
	
	private Bitmap originBitmap = null;
	private static final int PHOTO_SIZE_WIDTH = 1500;
	private static final int PHOTO_SIZE_HEIGHT = 1024;
	private File tempFile = new File("/sdcard/.a.jpg");
	
	private ProgressDialog progressDialog;
	private Bitmap changeBitmap = null;
	
	private DrawerLayout mDrawerLayout = null;
	private ActionBarDrawerToggle mDrawerToggle = null;
	private ActionBarHelper mActionBar = null;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		setUpDrawer();
		setUpList();
		
		changeStyleButton = (Button) findViewById(R.id.button);
		restoreButton = (Button) findViewById(R.id.button_restore);
		imageView = (ImageView) findViewById(R.id.image);
		imageInfoLayout = (LinearLayout) findViewById(R.id.image_info);
		imageHeightTextView = (TextView) findViewById(R.id.image_height);
		imageWidthTextView = (TextView) findViewById(R.id.image_width);
		changeStyleButton.setOnClickListener(this);
		restoreButton.setOnClickListener(this);
		
	}
	
	private void setUpList() {
		this.listView = (ListView) findViewById(R.id.filter_select);
		
		ArrayAdapter<String> adapter = new ArrayAdapter<String>(this, R.layout.list_content,
                Constant.styles);
		this.listView.setAdapter(adapter);
		this.listView.setOnItemClickListener(this);
	}
	
	private void setUpDrawer() {
		mDrawerLayout = (DrawerLayout) findViewById(R.id.drawer_layout);
		mDrawerLayout.setDrawerListener(new ImageDrawerListener());
        mDrawerLayout.setDrawerShadow(R.drawable.drawer_shadow, GravityCompat.START);
        
        mDrawerLayout.setDrawerTitle(GravityCompat.START, "Navigation");
        
        mActionBar = createActionBarHelper();
        mActionBar.init();

       
        mDrawerToggle = new ActionBarDrawerToggle(this, mDrawerLayout,
                R.drawable.ic_drawer, R.string.drawer_open, R.string.drawer_close);
	}
	
	@Override
    protected void onPostCreate(Bundle savedInstanceState) {
        super.onPostCreate(savedInstanceState);

   
        mDrawerToggle.syncState();
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (mDrawerToggle.onOptionsItemSelected(item)) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        mDrawerToggle.onConfigurationChanged(newConfig);
    }
	

    private ActionBarHelper createActionBarHelper() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH) {
            return new ActionBarHelperICS();
        } else {
            return new ActionBarHelper();
        }
    }


    private class ActionBarHelper {
        public void init() {}
        public void onDrawerClosed() {}
        public void onDrawerOpened() {}
        public void setTitle(CharSequence title) {}
    }

    private class ActionBarHelperICS extends ActionBarHelper {
        private final ActionBar mActionBar;
        private CharSequence mDrawerTitle;
        private CharSequence mTitle;

        ActionBarHelperICS() {
            mActionBar = getActionBar();
        }

        @Override
        public void init() {
            mActionBar.setDisplayHomeAsUpEnabled(true);
            mActionBar.setHomeButtonEnabled(true);
            mTitle = mDrawerTitle = getTitle();
        }


        @Override
        public void onDrawerClosed() {
            super.onDrawerClosed();
            mActionBar.setTitle(mTitle);
        }

        @Override
        public void onDrawerOpened() {
            super.onDrawerOpened();
            mActionBar.setTitle(mDrawerTitle);
        }

        @Override
        public void setTitle(CharSequence title) {
            mTitle = title;
        }
    }
	
	private class ImageDrawerListener implements DrawerLayout.DrawerListener {

		@Override
        public void onDrawerOpened(View drawerView) {
            mDrawerToggle.onDrawerOpened(drawerView);
            mActionBar.onDrawerOpened();
        }

        @Override
        public void onDrawerClosed(View drawerView) {
            mDrawerToggle.onDrawerClosed(drawerView);
            mActionBar.onDrawerClosed();
        }

        @Override
        public void onDrawerSlide(View drawerView, float slideOffset) {
            mDrawerToggle.onDrawerSlide(drawerView, slideOffset);
        }

        @Override
        public void onDrawerStateChanged(int newState) {
            mDrawerToggle.onDrawerStateChanged(newState);
        }
		
	}

	@Override
	public void onClick(View v) {
		// TODO Auto-generated method stub
		if (v.getId() == R.id.button) {
			Intent intent = new Intent(Intent.ACTION_GET_CONTENT);
			intent.setDataAndType(MediaStore.Images.Media.INTERNAL_CONTENT_URI,
					"image/*");
			intent.setType("image/*");
			intent.putExtra("output", Uri.fromFile(tempFile));
			intent.putExtra("crop", "true");
//			intent.putExtra("aspectX", 1);
//			intent.putExtra("aspectY", 1);
//			intent.putExtra("outputX", PHOTO_SIZE_WIDTH);
//			intent.putExtra("outputY", PHOTO_SIZE_HEIGHT);
			startActivityForResult(intent, 1);
		}
		else if (v.getId() == R.id.button_restore) {
			if (this.originBitmap != null) {
				this.imageView.setImageBitmap(originBitmap);
			}
		}
	}

	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
		// TODO Auto-generated method stub
		super.onActivityResult(requestCode, resultCode, data);
		if (resultCode == RESULT_OK) {
			originBitmap = BitmapFactory.decodeFile(tempFile.getAbsolutePath());
			if (originBitmap != null) {
				tempFile.delete();
				this.imageView.setImageBitmap(originBitmap);
				imageInfoLayout.setVisibility(View.VISIBLE);
				imageWidthTextView.setText("Width: " + originBitmap.getWidth());
				imageHeightTextView.setText("Height: " + originBitmap.getHeight());
			}		
		}
	}

	
	private Handler handler = new Handler() {

		@Override
		public void handleMessage(Message msg) {
			// TODO Auto-generated method stub
			super.handleMessage(msg);
			imageView.setImageBitmap(changeBitmap);
			progressDialog.dismiss();
			mDrawerLayout.closeDrawers();
		}
		
	};
	
	@Override
	public void onItemClick(AdapterView<?> arg0, View arg1, final int pos, long arg3) {
		// TODO Auto-generated method stub
		if (originBitmap != null) {
			progressDialog = ProgressDialog.show(this, "", "", true);
			new Thread() {
				@Override
				public void run() {
					// TODO Auto-generated method stub
					super.run();
					applyStyle(pos + 1);
					Message msg = Message.obtain();
					msg.what = 1;
					handler.sendMessage(msg);
				}

			}.start();
		} else {
			Toast.makeText(getApplicationContext(), "Please select an image", Toast.LENGTH_LONG).show();
			mDrawerLayout.closeDrawers();
		}
	}
	
	private void applyStyle(int styleNo) {
		switch (styleNo) {
		case BitmapFilter.AVERAGE_BLUR_STYLE:
			changeBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.AVERAGE_BLUR_STYLE, 5); // maskSize, must odd
			break;
		case BitmapFilter.GAUSSIAN_BLUR_STYLE:
			changeBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.GAUSSIAN_BLUR_STYLE, 1.2); // sigma
			break;
		case BitmapFilter.SOFT_GLOW_STYLE:
			changeBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.SOFT_GLOW_STYLE, 0.6);
			break;
		case BitmapFilter.LIGHT_STYLE:
			int width = originBitmap.getWidth();
			int height = originBitmap.getHeight();
			changeBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.LIGHT_STYLE, width / 3, height / 2, width / 2);
			break;
		case BitmapFilter.LOMO_STYLE:
			changeBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.LOMO_STYLE, 
					(originBitmap.getWidth() / 2.0) * 95 / 100.0);
			break;
		case BitmapFilter.NEON_STYLE:
			changeBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.NEON_STYLE, 200, 100, 50);
			break;
		case BitmapFilter.PIXELATE_STYLE:
			changeBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.PIXELATE_STYLE, 10);
			break;
		case BitmapFilter.MOTION_BLUR_STYLE:
			changeBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.MOTION_BLUR_STYLE, 10, 1);
			break;
		case BitmapFilter.OIL_STYLE:
			changeBitmap = BitmapFilter.changeStyle(originBitmap, BitmapFilter.OIL_STYLE, 10);
			break;
		default:
			changeBitmap = BitmapFilter.changeStyle(originBitmap, styleNo);
			break;
		}
	}
}
