using UnityEngine;

public class Body : MonoBehaviour {
    [HideInInspector]
    public Vector3[] WheelAttatchmentPositions = new Vector3[4];

	// Use this for initialization
	private void Awake () {
        WheelAttatchmentPositions[0] = new Vector3(-0.5F, -0.5F, -0.5F);
        WheelAttatchmentPositions[1] = new Vector3(-0.5F, -0.5F, 0.5F);
        WheelAttatchmentPositions[2] = new Vector3(0.5F, -0.5F, 0.5F);
        WheelAttatchmentPositions[3] = new Vector3(0.5F, -0.5F, -0.5F);
    }
	
    public virtual float CalculateSpeed(float carSpeed)
    {
        return carSpeed;
    }
}
