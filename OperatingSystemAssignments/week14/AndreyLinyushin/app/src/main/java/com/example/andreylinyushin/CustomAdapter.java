package com.example.andreylinyushin;

import android.app.Activity;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

public class CustomAdapter extends ArrayAdapter<String> {
    private ListView listView;
    ArrayList<String> tasks;

    public CustomAdapter(Context context, int textViewResourceId, ArrayList<String> objects, ListView listView) {
        super(context, textViewResourceId, objects);
        this.listView = listView;
        tasks = objects;
    }


    static class ViewHolder {
        TextView text;
        Button btn;
    }

    @Override
    public View getView(final int position, View convertView, ViewGroup parent) {
        View rowView = convertView;

        if (rowView == null) {
            LayoutInflater inflater = ((Activity) getContext()).getLayoutInflater();
            rowView = inflater.inflate(R.layout.todo_item, parent, false);
            ViewHolder h = new ViewHolder();
            h.text = (TextView) rowView.findViewById(R.id.task_title);
            h.btn = rowView.findViewById(R.id.task_view);
            rowView.setTag(h);
        }

        ViewHolder h = (ViewHolder) rowView.getTag();

        h.text.setText(tasks.get(position));
        h.btn.setOnClickListener(v -> {
            tasks.remove(position);
            notifyDataSetChanged();
        });

        return rowView;
    }
}