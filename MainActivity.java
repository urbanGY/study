package software.pinetree.blue.ssubs;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Build;
import android.speech.RecognitionListener;
import android.speech.RecognizerIntent;
import android.speech.SpeechRecognizer;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.animation.Animation;
import android.view.animation.AnimationUtils;
import android.widget.ImageView;
import android.widget.TextView;

import org.json.JSONObject;

import java.util.ArrayList;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";
    TextView textView;
    TextView level;
    TextView key;
    ImageView imageView;
    ImageView circle;

    Animation animation;

    private SpeechRecognizer mSpeechRecognizer;
    private Intent mSpeechRecognizerIntent;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        checkPermission();
        textView = findViewById(R.id.speechText);
        level = findViewById(R.id.level);
        key = findViewById(R.id.keyWord);
        imageView = findViewById(R.id.recording);
        circle = findViewById(R.id.circle);

        animation = AnimationUtils.loadAnimation(getApplicationContext(),R.anim.scale);

        mSpeechRecognizer = SpeechRecognizer.createSpeechRecognizer(this);
        mSpeechRecognizerIntent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
        mSpeechRecognizerIntent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM );
        mSpeechRecognizerIntent.putExtra(RecognizerIntent.EXTRA_LANGUAGE, Locale.KOREAN);
        Log.d(TAG, "onCreate: create intent all");

        mSpeechRecognizer.setRecognitionListener(new RecognitionListener() {
            @Override
            public void onReadyForSpeech(Bundle bundle) {
                Log.d(TAG, "onReadyForSpeech: ");
                level.setText("start speech...");
            }

            @Override
            public void onBeginningOfSpeech() {
                Log.d(TAG, "onBeginningOfSpeech: ");

            }

            @Override
            public void onRmsChanged(float v) {
                Log.d(TAG, "onRmsChanged: "+ v);
                level.setText("start speech..."+v);
                if(v > 0.0){
                    circle.startAnimation(animation);
                }
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
                textView.setText("error...");
                level.setText("level");
            }

            @Override
            public void onResults(Bundle bundle) {
                Log.d(TAG, "onResults: before get result");
                ArrayList<String> matches = bundle.getStringArrayList(SpeechRecognizer.RESULTS_RECOGNITION);
                Log.d(TAG, "onResults: "+matches.get(0));
                if(matches != null)
                    textView.setText(matches.get(0));
                level.setText("level");
                /*
                loading icon
                 */
                /*
                oepn thread, post masage
                 */
                JSONObject json = new JSONObject();
                String value = "";
                try {
                    json.put("text", matches.get(0));
                    value = json.toString();
                }catch (Exception e){
                    e.printStackTrace();
                }
                Log.d(TAG, "value: "+value);
                new ServerCall(key).execute(value);
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

        imageView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.d(TAG, "onClick: click image!");
                textView.setText("listening...");
                mSpeechRecognizer.startListening(mSpeechRecognizerIntent);
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
