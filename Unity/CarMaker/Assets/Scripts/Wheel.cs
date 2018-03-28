using UnityEngine;

public class Wheel : MonoBehaviour {

    public virtual float CalculateSpeed(float carSpeed)
    {
        return carSpeed;
    }
}
