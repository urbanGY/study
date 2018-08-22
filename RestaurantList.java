package blue.pinetree.software.reservation;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import org.json.JSONArray;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class RestaurantList extends AppCompatActivity {
    private ArrayList<HashMap<String, String>> foodList;
    private SimpleAdapter adapter;

    private ListView food_list;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_restaurant_list);

        food_list = findViewById(R.id.food_list);

        foodList = new ArrayList<HashMap<String, String>>();
        Intent intent = getIntent();
        Parsing(intent.getStringExtra("categoryList"));

        String[] from = new String[]{"name","cur","total"};
        int[] to = new int[]{R.id.food_list_cur, R.id.food_list_name, R.id.food_list_total};
        adapter = new SimpleAdapter(this, foodList, R.layout.food_list_layout, from, to);
        food_list.setAdapter(adapter);

        food_list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {
                String name = foodList.get(i).get("name");
                new GetInfo(getApplicationContext()).execute(name);
            }
        });
    }

    private void Parsing(String list){
        try{
            JSONArray jarray = new JSONObject(list).getJSONArray("food_list");
            for (int i = 0 ; i < jarray.length() ; i++){
                JSONObject job = jarray.getJSONObject(i);
                String name = job.getString("name");
                String cur = job.getString("cur_seat");
                String total = job.getString("total_seat");

                HashMap<String,String> map = new HashMap<String, String>();
                map.put("name",name);
                map.put("cur",cur+" / ");
                map.put("total",total);

                foodList.add(map);
            }
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
