#ifndef SW_INTERFACE_H

#define SW_INTERFACE_H

#define SW_u8SelfLocked 0
#define SW_u8NotSelfLocked 1

#define SW_u8PullDown   0
#define SW_u8PullUp   1

#define SW_u8NotPressed 0
#define SW_u8Pressed 1

#define SW_u8HIGH  1
#define SW_u8LOW  0

u8 SW_u8GetState(u8 SW_u8PORT, u8 SW_u8PIN , u8 SW_u8LockingType,u8 SW_u8PullType);

#endif
