//
//  PltUPnPObject.h
//  Platinum
//
//  Created by Sylvain on 9/14/10.
//  Copyright 2010 Plutinosoft LLC. All rights reserved.
//

#import <Neptune/Neptune.h>

#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
#include <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
#endif


#if !defined(_PLATINUM_H_)
typedef struct PLT_UPnP PLT_UPnP;
typedef struct PLT_Action PLT_Action;
typedef struct PLT_DeviceHostReference PLT_DeviceHostReference;
#endif

/*----------------------------------------------------------------------
|   PLT_ActionObject
+---------------------------------------------------------------------*/
@interface PLT_ActionObject : NSObject {
@private
    PLT_Action* action;
}

- (id)initWithAction:(PLT_Action *)_action;
- (NPT_Result)setValue:(NSString*)value forArgument:(NSString*)argument;
- (NPT_Result)setErrorCode:(unsigned int)code withDescription:(NSString*)description;
@end

/*----------------------------------------------------------------------
|   PLT_DeviceHostObject
+---------------------------------------------------------------------*/
@interface PLT_DeviceHostObject : NSObject {
@private
    PLT_DeviceHostReference* device;
}

- (void)setDevice:(PLT_DeviceHostReference*)_device;
- (PLT_DeviceHostReference&)getDevice;
@end

/*----------------------------------------------------------------------
|   PLT_UPnPObject
+---------------------------------------------------------------------*/
@interface PLT_UPnPObject : NSObject

- (NPT_Result)start;
- (NPT_Result)stop;
- (bool)isRunning;

- (NPT_Result)addDevice:(PLT_DeviceHostObject*)device;
- (NPT_Result)removeDevice:(PLT_DeviceHostObject*)device;

@end
