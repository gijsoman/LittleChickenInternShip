using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class BuildingSceneManager : MonoBehaviour {

    public Car Car;

    public Text WarningField;

    public void LoadDriveScene()
    {
        //Check if the car has wheels and a body.
        if (Car.Body != null && Car.Wheel != null)
        {
            SceneManager.LoadScene(1);
        }
        else
        {
            WarningField.text = "This car doesn't have any wheels!";
        }
    }
}
