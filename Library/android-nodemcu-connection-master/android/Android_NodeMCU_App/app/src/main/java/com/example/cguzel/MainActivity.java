package com.example.cguzel.nodemcu_app;

import android.content.Context;
import android.os.AsyncTask;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.example.cguzel.HttpRequestTask;

import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URI;
import java.net.URISyntaxException;

/**
 * Created by cguzel on 26.04.2016.
 */

//http://192.168.4.1/   - data going address

public class MainActivity extends AppCompatActivity {

    final Context context = this;
    private EditText ipAddress;
    private Button ledOn, ledOff;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ipAddress = (EditText) findViewById(R.id.edt_ip);
        ledOn = (Button) findViewById(R.id.btn_ledOn);
        ledOff = (Button) findViewById(R.id.btn_ledOff);

    }

    /** When the button clicks this method executes**/
    public void buttonClick(View view) {
        String ledStatus;

        if (ipAddress.getText().toString().equals(""))
            Toast.makeText(MainActivity.this, "Please enter the ip address...", Toast.LENGTH_SHORT).show();

        else {
            if (view == ledOn)
                ledStatus = "1";

            else
                ledStatus = "0";

            //Connect to default port number. Ex: http://IpAddress:80
            String serverAdress = ipAddress.getText().toString() + ":" + "80";
            HttpRequestTask requestTask = new HttpRequestTask(serverAdress,context);
            requestTask.execute(ledStatus);
        }
    }

    ////////////////////////////////////Sending url commands to Node//////////////////////////////////////////

}
