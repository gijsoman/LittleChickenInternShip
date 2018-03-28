using UnityEngine;
using UnityEngine.SceneManagement;

public class Car : MonoBehaviour {

    public Body Body;
    public Wheel Wheel;
    public CarController CarController;

    private float bodySpeed;
    private float wheelSpeed;

    private void OnDestroy()
    {
        SceneManager.sceneLoaded -= OnSceneLoaded;
    }

    private void Start()
    {
        SceneManager.sceneLoaded += OnSceneLoaded;
    }

    private void OnSceneLoaded(Scene scene, LoadSceneMode loadSceneMode)
    {
        Debug.Log(scene.buildIndex);
        if (scene.buildIndex == 1 && CarController.enabled == false)
        {
            transform.GetChild(0).gameObject.SetActive(true);
            CarController.enabled = true;
        }
        if (scene.buildIndex == 0 && CarController.enabled == true)
        {
            Destroy(this.gameObject);
        }
    }


    public void SwitchBody()
    {
        Body = transform.GetComponentInChildren<Body>();
        CalculateBodySpeed();
        ChangeSpeedNow();
    }

    public void SwitchWheels()
    {
        Wheel = Body.GetComponentInChildren<Wheel>();
        CalculateWheelSpeed();
        ChangeSpeedNow();
    }

    public void ChangeSpeedNow()
    {
        CarController.resetSpeed();
        CarController.speed = bodySpeed + wheelSpeed;
    }

    //Uses the calculateSpeed function of the body to calculate the body speed.
    private void CalculateBodySpeed()
    {
        bodySpeed = 0;
        CarController.resetSpeed();
        bodySpeed = Body.CalculateSpeed(CarController.speed);
    }
    //Uses the calculateSpeed function of the wheels to calculate the wheel speed.
    private void CalculateWheelSpeed()
    {
        wheelSpeed = 0;
        CarController.resetSpeed();
        wheelSpeed = Wheel.CalculateSpeed(CarController.speed);
    }


}
