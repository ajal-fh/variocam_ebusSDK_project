
#include <PvSampleUtils.h>
#include <PvDevice.h>

PV_INIT_SIGNAL_HANDLER();

PvDevice* ConnectDevice()
{
    PvResult lResult = PvResult::Code::INVALID_PARAMETER;

    // Select device
    PvString lConnectionID;
    if ( !PvSelectDevice( &lConnectionID ) )
    {
        cout << "No device selected." << endl;
        return NULL;
    }

    // Creates and connects the device controller based on the selected device. 
    cout << "Connecting to device" << endl;
    PvDevice *lDevice = PvDevice::CreateAndConnect( lConnectionID, &lResult );
    if ( ( lDevice == NULL ) || !lResult.IsOK() )
    {
        cout << "Unable to connect to device" << endl;
        return NULL;
    }

    return lDevice;
}


int main( int argc, char* argv[] )
{
    PV_SAMPLE_INIT();

    cout << "PvCameraBridge sample - camera control through a Pleora video interface" << endl << endl;

    // Select, connect a PvDevice
    PvDevice* lDevice = ConnectDevice();
    if ( lDevice == NULL )
    {
        return -1;
    }

        // Device created with PvDevice::CreateAndConnect, release with PvDevice::Free
    PvDevice::Free( lDevice );

    PV_SAMPLE_TERMINATE();

    return 0;
}
