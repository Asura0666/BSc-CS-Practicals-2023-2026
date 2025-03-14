
package com.example.myspinner
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.AdapterView
import android.widget.AdapterView.OnItemSelectedListener
import android.widget.ArrayAdapter
import android.widget.Spinner
import android.widget.Toast
class MainActivity : AppCompatActivity(),OnItemSelectedListener {
    var courses = arrayOf<String?>("C", "Data Structure", "Interview prep", "Algorithms", "DSA with Java", "OS")
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val spin = findViewById<Spinner>(R.id.coursesspinner)
        spin.onItemSelectedListener = this
        val ad: ArrayAdapter<*> = ArrayAdapter<Any?>(
            this,
            android.R.layout.simple_spinner_item, courses
        )
        ad.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item)
        spin.adapter = ad
    }
    override fun onItemSelected(parent: AdapterView<*>?, view: View, position: Int, id: Long) {
        Toast.makeText(applicationContext, courses[position], Toast.LENGTH_LONG).show()
    }
    override fun onNothingSelected(parent: AdapterView<*>?) {}
    }
