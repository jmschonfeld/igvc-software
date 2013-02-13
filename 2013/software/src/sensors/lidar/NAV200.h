/*
 * NAV200.h
 *
 *  Created on: Jan 22, 2012
 *      Author: Alexander Huynh
Copypasta from: Matthew Barulic
 */
#ifndef NAV200_H
#define NAV200_H

#include "Lidar.h"
#include <libusb-1.0/libusb.h>
#include "serial/ASIOSerialPort.h"



namespace IGVC {
namespace Sensors {

class NAV200: public Lidar {
public:
    NAV200();
    ~NAV200();
    LidarState GetState();
    LidarState GetStateAtTime(timeval time);
    bool StateIsAvailable();
    void stop();

private:

    //ASIOSerialPort serialPort;
    boost::thread _iothread;
    boost::mutex _queueLocker;
    libusb_device_handle *_handle;
    libusb_context *_ctx;
    bool _running;
    int _numPoints;

    void threadRun(); // the method that runs on iothread
};

} /* namespace Sensors */
} /* namespace IGVC */
#endif // NAV200_H
