public class TerrainWheel : Wheel {

    public override float CalculateSpeed(float carSpeed)
    {
        carSpeed -= 10;
        return carSpeed;
    }
}
