package org.bevylabs.mathsgame;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView num1Txt=findViewById(R.id.textView);
        TextView num2Txt=findViewById(R.id.textView4);
        EditText resultTxt=findViewById(R.id.editText);


    }

    public void check(View view) {

    }
}
