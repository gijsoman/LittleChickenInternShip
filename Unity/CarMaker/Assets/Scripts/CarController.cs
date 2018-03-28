using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CarController : MonoBehaviour {

    public float speed = 10.0F;
    public float rotationSpeed = 100.0F;

	void Start () {
		
	}
	
	void Update () {
        float translation = Input.GetAxis("Vertical") * speed;
        translation *= Time.deltaTime;

        transform.Translate(translation, 0,0);

        if (Input.GetKey(KeyCode.A))
        {
            transform.Rotate(-Vector3.up * rotationSpeed * Time.deltaTime);
        }
        if(Input.GetKey(KeyCode.D))
        {
            transform.Rotate(Vector3.up * rotationSpeed * Time.deltaTime);
        }
	}

    public void resetSpeed()
    {
        speed = 10F;
    }
}
