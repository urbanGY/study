package blue.pinetree.software.reservation;

import android.content.Intent;
import android.content.SharedPreferences;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

import blue.pinetree.software.reservation.hostActivity.HostActivity;
import blue.pinetree.software.reservation.hostActivity.LoginActivity;
import blue.pinetree.software.reservation.userActivity.RestaurantList;
import blue.pinetree.software.reservation.userServer.GetList;

public class MainActivity extends AppCompatActivity {
    private ImageView category_1;
    private Button loginButton;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        loginButton = findViewById(R.id.loginButton);
        final SharedPreferences pref = getSharedPreferences("login",MODE_PRIVATE);

        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String check = pref.getString("login","fail");
                Intent intent;
                if(check.equals("success")){
                    intent = new Intent(getApplicationContext(), HostActivity.class);
                }else {
                    intent = new Intent(getApplicationContext(), LoginActivity.class);
                }
                startActivity(intent);
            }
        });

        category_1 = findViewById(R.id.category_1);

        final String category_num = "1";
        category_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new GetList(getApplicationContext()).execute(category_num);
            }
        });
    }
}
