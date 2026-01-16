#import "AppDelegate.h"
// #import <GoogleSignIn/GoogleSignIn.h>
// #import "FirebaseAuth-Swift.h"

@import UserNotifications;
// @import AuthenticationServices;

// @interface AppDelegate (FirebasePlugin) <UIApplicationDelegate, ASAuthorizationControllerDelegate, ASAuthorizationControllerPresentationContextProviding>
@interface AppDelegate (FirebasePlugin) <UIApplicationDelegate>
+ (AppDelegate *_Nonnull) instance;
@property (nonatomic, strong) NSNumber * _Nonnull applicationInBackground;
@end
