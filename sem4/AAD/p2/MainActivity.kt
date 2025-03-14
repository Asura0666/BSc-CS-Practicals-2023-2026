
package com.example.myappp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
    }

    fun abc(view: View) {
        Toast.makeText(applicationContext,"HELLO KIRTI COLLEGE",Toast.LENGTH_LONG).show()
    }
}
