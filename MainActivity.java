package software.pinetree.blue.ssubs;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Build;
import android.provider.Settings;
import android.speech.RecognitionListener;
import android.speech.RecognizerIntent;
import android.speech.SpeechRecognizer;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    TextView textView;

    private SpeechRecognizer mSpeechRecognizer;
    private Intent mSpeechRecognizerIntent;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        checkPermission();
        textView = findViewById(R.id.speechText);

        mSpeechRecognizer = SpeechRecognizer.createSpeechRecognizer(this);
        mSpeechRecognizerIntent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
        mSpeechRecognizerIntent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM );
        mSpeechRecognizerIntent.putExtra(RecognizerIntent.EXTRA_LANGUAGE, Locale.KOREAN);
        Log.d(TAG, "onCreate: create intent all");
        mSpeechRecognizer.setRecognitionListener(new RecognitionListener() {
            @Override
            public void onReadyForSpeech(Bundle bundle) {
                Log.d(TAG, "onReadyForSpeech: ");
            }

            @Override
            public void onBeginningOfSpeech() {
                Log.d(TAG, "onBeginningOfSpeech: ");

            }

            @Override
            public void onRmsChanged(float v) {
                Log.d(TAG, "onRmsChanged: ");
            }

            @Override
            public void onBufferReceived(byte[] bytes) {
                Log.d(TAG, "onBufferReceived: ");
            }

            @Override
            public void onEndOfSpeech() {
                Log.d(TAG, "onEndOfSpeech: ");
            }

            @Override
            public void onError(int i) {
                Log.d(TAG, "onError: "+ i);
            }

            @Override
            public void onResults(Bundle bundle) {
                Log.d(TAG, "onResults: before get result");
                ArrayList<String> matches = bundle.getStringArrayList(SpeechRecognizer.RESULTS_RECOGNITION);
                Log.d(TAG, "onResults: "+matches.get(0));
                if(matches != null)
                    textView.setText(matches.get(0));
            }

            @Override
            public void onPartialResults(Bundle bundle) {
                Log.d(TAG, "onPartialResults: ");
            }

            @Override
            public void onEvent(int i, Bundle bundle) {
                Log.d(TAG, "onEvent: ");
            }
        });

        findViewById(R.id.button).setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View view, MotionEvent motionEvent) {
                switch (motionEvent.getAction()) {
                    case MotionEvent.ACTION_UP:
                        Log.d(TAG, "onTouch: no click");
                        mSpeechRecognizer.stopListening();
                        textView.setHint("you will see the input here");
                        break;
                    case MotionEvent.ACTION_DOWN:
                        Log.d(TAG, "onTouch: click");
                        textView.setText("");
                        textView.setHint("Listen...");
                        mSpeechRecognizer.startListening(mSpeechRecognizerIntent);
                        break;
                }
                return false;
            }
        });
    }

    private void checkPermission() {
        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            if(ContextCompat.checkSelfPermission( this, Manifest.permission.RECORD_AUDIO) != PackageManager.PERMISSION_GRANTED) {
                ActivityCompat.requestPermissions(this, new String[] {Manifest.permission.RECORD_AUDIO}, 1);
            }
        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (Build.VERSION.SDK_INT >= 23) {
            if(grantResults[0]== PackageManager.PERMISSION_GRANTED){
                Log.v(TAG,"Permission: "+permissions[0]+ "was "+grantResults[0]);
                //resume tasks needing this permission
            }
        }
    }
}
