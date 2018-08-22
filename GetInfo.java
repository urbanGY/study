package blue.pinetree.software.reservation;

import android.content.Context;
import android.content.Intent;
import android.os.AsyncTask;

public class GetInfo extends AsyncTask<String,Void,String> {
    private Context context;

    private String URL = "hh";
    public GetInfo(Context context){
        this.context = context;
    }

    @Override
    protected String doInBackground(String... name) {
        URL += name[0];
        String result = "fail";



        return result;
    }

    @Override
    protected void onPostExecute(String s) {
        super.onPostExecute(s);
        Intent intent = new Intent(context, Info.class);
        intent.putExtra("information",s);
        context.startActivity(intent);
    }
}
