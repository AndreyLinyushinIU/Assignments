package com.example.andreylinyushin;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;

import java.util.ArrayList;


public class MainActivity extends AppCompatActivity {
    ArrayList<String> taskList = new ArrayList<String>();
    CustomAdapter mAdapter;
    ListView mTaskListView;
    private static final String TAG = "TAG";

    @Override
    protected void onCreate ( Bundle savedInstanceState ) {
        super . onCreate ( savedInstanceState );
        setContentView (R. layout . activity_main );
        mTaskListView = ( ListView ) findViewById (R.id. list_todo );
        mAdapter = new CustomAdapter(this, R.id.task_title, taskList, mTaskListView);
        mTaskListView.setAdapter(mAdapter);
    }
    @Override
    public boolean onCreateOptionsMenu ( Menu menu ) {
        getMenuInflater () . inflate (R. menu . main_menu , menu );
        return super . onCreateOptionsMenu ( menu ) ;
    }
    @Override
    public boolean onOptionsItemSelected ( MenuItem item ) {
        final EditText taskEditText = new EditText ( this );
        AlertDialog dialog = new AlertDialog.Builder(this).setTitle("Add a new task").setMessage("What do you want to do next ?").setView(taskEditText)
                .setPositiveButton (" Add " , (dialog1, which) -> {
                    String task = String.valueOf(taskEditText.getText());
                    Log.d("smthsmth"," ask to add: " + task);
                    taskList.add(String.valueOf(taskEditText.getText()));
                    Log.d("smthsmth", String.valueOf(taskEditText.getText()));
                    mAdapter.notifyDataSetChanged();
                })
                .setNegativeButton ("Cancel " , null)
                .create() ;
        dialog.show() ;
        return true;
    }

    public void removeItem (View view) {
        taskList.remove(view.toString());
        mAdapter.notifyDataSetChanged();
    }

}