package blue.pinetree.software.reservation;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

import org.json.JSONArray;
import org.json.JSONObject;

public class RestaurantList extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_restaurant_list);
        Intent intent = getIntent();
        Parsing(intent.getStringExtra("categoryList"));
    }

    private void Parsing(String list){
        String NAME = "";
        String CUR_SEAT = "";
        String TOTAL_SEAT = "";
        try{
            JSONArray jarray = new JSONObject(list).getJSONArray("food_list");
            for (int i = 0 ; i < jarray.length() ; i++){
                JSONObject job = jarray.getJSONObject(i);
                job.optString(NAME);

            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
