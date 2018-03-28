using UnityEngine;

public class BigBody : Body {

	// Use this for initialization
	private void Awake () {
        WheelAttatchmentPositions[0] = new Vector3(-0.5F, -0.5F, -0.5F);
        WheelAttatchmentPositions[1] = new Vector3(-0.5F, -0.5F, 0.5F);
        WheelAttatchmentPositions[2] = new Vector3(0.5F, -0.5F, 0.5F);
        WheelAttatchmentPositions[3] = new Vector3(0.5F, -0.5F, -0.5F);
    }

    public override float CalculateSpeed(float carSpeed)
    {
        carSpeed -= 5;
        return carSpeed;
    }
}
