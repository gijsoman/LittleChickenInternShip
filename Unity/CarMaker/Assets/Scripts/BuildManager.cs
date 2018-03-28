using System;
using System.Collections.Generic;
using System.Collections;
using UnityEngine;

public class BuildManager : MonoBehaviour {
    public Car playerCar;

    public List<GameObject> Chassis;
    public List<GameObject> Wheels;

    private GameObject instantiatedBody;
    private List<GameObject> instantiatedWheels = new List<GameObject>();

    private int currentBody;
    private int currentWheels;

    private void Start()
    {
        InitizlizeCar();

    }

    private void InitizlizeCar()
    {
        SpawnBody(1);
        SpawnSetOfWheels(1);
    }

    public void SpawnBody(int selectedBody)
    {
        //Check if the selected body isn't the same as the currentBody. Only then we instantiate a new one.
        if (selectedBody != currentBody)
        {
            StartCoroutine(InstantiateBody(selectedBody));
        }
    }

    public void SpawnSetOfWheels(int selectedWheels)
    {
        //Check if there is a body and check if the selected wheels aren't the same as the current wheels.
        if (instantiatedBody != null && selectedWheels != currentWheels)
        {
            StartCoroutine(InstantiateWheels(selectedWheels));
        }
    }

    private IEnumerator InstantiateBody(int selectedBody)
    {
        //We only destroy the instantiated body if it isn't null otherwise there is nothing to destroy.
        if (instantiatedBody != null)
        {
            Destroy(instantiatedBody);
        }

        // Wait for garbage collection
        yield return new WaitForEndOfFrame();

        //Instantiate a new body from the list of available bodies. It will only instantiate when this function is finished?
        instantiatedBody = Instantiate(Chassis[selectedBody], transform.position, Quaternion.identity, playerCar.gameObject.transform);
        playerCar.SwitchBody();
        currentBody = selectedBody;

        // deref wheels & reset wheel index
        instantiatedWheels.Clear();
        currentWheels = -1;

        yield return null;
    }

    private IEnumerator InstantiateWheels(int selectedWheels)
    {
        //Only if instantiatedwheels is not empty we can destroy the old wheels
        if (instantiatedWheels.Count != 0)
        {
            for (int i = 0; i < instantiatedWheels.Count; i++)
            {
                Destroy(instantiatedWheels[i]);
            }
            instantiatedWheels.Clear();
        }

        // wait for garbage collection
        yield return new WaitForEndOfFrame();

        //Instantiate the wheels at location.
        for (int i = 0; i < 4; i++)
        {
            instantiatedWheels.Add(Instantiate(Wheels[selectedWheels], transform.position, Quaternion.identity));
            instantiatedWheels[i].gameObject.transform.parent = instantiatedBody.transform;
            instantiatedWheels[i].gameObject.transform.localPosition = instantiatedBody.GetComponent<Body>().WheelAttatchmentPositions[i];
        }

        playerCar.SwitchWheels();
        currentWheels = selectedWheels;

        yield return null;
    }
}
