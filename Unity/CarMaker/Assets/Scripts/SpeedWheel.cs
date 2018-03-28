public class SpeedWheel : Wheel
{
    public override float CalculateSpeed(float carSpeed)
    {
        carSpeed += 10;
        return carSpeed;
    }
}