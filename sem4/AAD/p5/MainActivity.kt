package com.example.mylogin
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.Button
import android.widget.EditText
import android.widget.Toast

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        val et_user_name =findViewById<EditText>(R.id.editUser)
        val et_password =findViewById<EditText>(R.id.editPassword)

        val btn_submit = findViewById<Button>(R.id.button)
        btn_submit.setOnClickListener {
            val username = et_user_name.text.toString()
            val password = et_password.text.toString()
            if (username == "abc" && password == "1234") {
                Toast.makeText(this@MainActivity,"Login Successful", Toast.LENGTH_SHORT).show()
            }
        }
    }
}
