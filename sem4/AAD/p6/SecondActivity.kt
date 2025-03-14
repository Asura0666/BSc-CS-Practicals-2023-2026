package com.example.p6

import android.os.Bundle
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity
import com.example.p6.R.*

class SecondActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(layout.activity_second)

        val textView = findViewById<TextView>(id.textView)
        textView.text = "This is Second Activity"
    }
}