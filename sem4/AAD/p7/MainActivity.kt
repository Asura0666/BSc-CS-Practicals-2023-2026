package com.example.myradio

import android.os.Bundle
import android.widget.Button
import android.widget.RadioButton
import android.widget.RadioGroup
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {
    private lateinit var radioGroup: RadioGroup
    private lateinit var radioButton: RadioButton
    private lateinit var button: Button

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        title = "KotlinApp"

        radioGroup = findViewById(R.id.radioGroup)
        button = findViewById(R.id.btnDisplay)

        button.setOnClickListener {
            val selectedButtonId: Int = radioGroup.checkedRadioButtonId
            if (selectedButtonId != -1) {
                radioButton = findViewById(selectedButtonId)
                Toast.makeText(this, "Selected: ${radioButton.text}", Toast.LENGTH_SHORT).show()
            } else {
                Toast.makeText(this, "Please select an option", Toast.LENGTH_SHORT).show()
            }
        }
    }
}
