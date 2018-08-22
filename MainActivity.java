package blue.pinetree.software.reservation;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {
    ImageView category_1;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        category_1 = findViewById(R.id.category_1);
        final Intent intent = new Intent(this, RestaurantList.class);

        final String category_num = "1";
        category_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                new GetList(getApplicationContext()).execute(category_num);
            }
        });
    }
}
