using UnityEngine;
using UnityEngine.SceneManagement;

public class DrivingSceneManager : MonoBehaviour {

    public void BackToBuilding()
    {
        SceneManager.LoadScene(0);
    }
}
