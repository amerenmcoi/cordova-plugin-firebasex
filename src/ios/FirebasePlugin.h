#import <Cordova/CDV.h>
#import "AppDelegate.h"
#import "FirebaseWrapper.h"

@interface FirebasePlugin : CDVPlugin

- (void)setAutoInitEnabled:(CDVInvokedUrlCommand*)command;
- (void)isAutoInitEnabled:(CDVInvokedUrlCommand*)command;
- (void)sendPendingNotifications;

// Remote notifications
- (void)getId:(CDVInvokedUrlCommand*)command;
- (void)getToken:(CDVInvokedUrlCommand*)command;
- (void)getAPNSToken:(CDVInvokedUrlCommand*)command;
- (NSString *)hexadecimalStringFromData:(NSData *)data;
- (void)grantPermission:(CDVInvokedUrlCommand*)command;
- (void)hasPermission:(CDVInvokedUrlCommand*)command;
- (void)grantCriticalPermission:(CDVInvokedUrlCommand*)command;
- (void)hasCriticalPermission:(CDVInvokedUrlCommand*)command;
- (void)setBadgeNumber:(CDVInvokedUrlCommand*)command;
- (void)getBadgeNumber:(CDVInvokedUrlCommand*)command;
- (void)subscribe:(CDVInvokedUrlCommand*)command;
- (void)unsubscribe:(CDVInvokedUrlCommand*)command;
- (void)unregister:(CDVInvokedUrlCommand*)command;
- (void)onOpenSettings:(CDVInvokedUrlCommand*)command;
- (void)onMessageReceived:(CDVInvokedUrlCommand*)command;
- (void)onTokenRefresh:(CDVInvokedUrlCommand*)command;
- (void)onApnsTokenReceived:(CDVInvokedUrlCommand *)command;
- (void)sendOpenNotificationSettings;
- (void)sendNotification:(NSDictionary*)userInfo;
- (void)sendToken:(NSString*)token;
- (void)sendApnsToken:(NSString*)token;
- (void)clearAllNotifications:(CDVInvokedUrlCommand *)command;

// Remote config
- (void)fetch:(CDVInvokedUrlCommand*)command;
- (void)activateFetched:(CDVInvokedUrlCommand*)command;
- (void)getValue:(CDVInvokedUrlCommand*)command;
- (void)getInfo:(CDVInvokedUrlCommand*)command;
- (void)fetchAndActivate:(CDVInvokedUrlCommand*)command;
- (void)getAll:(CDVInvokedUrlCommand*)command;
- (void)resetRemoteConfig:(CDVInvokedUrlCommand*)command;
- (void)setConfigSettings:(CDVInvokedUrlCommand*)command;
- (void)setDefaults:(CDVInvokedUrlCommand*)command;


// Internals
+ (FirebasePlugin *) firebasePlugin;
+ (NSString*) appleSignInNonce;
+ (void) setFirestore:(FIRFirestore*) firestoreInstance;
- (void) handlePluginExceptionWithContext: (NSException*) exception :(CDVInvokedUrlCommand*)command;
- (void) handlePluginExceptionWithoutContext: (NSException*) exception;
- (void) _logError: (NSString*)msg;
- (void) _logInfo: (NSString*)msg;
- (void) _logMessage: (NSString*)msg;
- (BOOL) _shouldEnableCrashlytics;
- (NSNumber*) saveAuthCredential: (FIRAuthCredential *) authCredential;
- (void)executeGlobalJavascript: (NSString*)jsString;

- (void)createChannel:(CDVInvokedUrlCommand *)command;
- (void)setDefaultChannel:(CDVInvokedUrlCommand *)command;
- (void)deleteChannel:(CDVInvokedUrlCommand *)command;
- (void)listChannels:(CDVInvokedUrlCommand *)command;

@property (nonatomic, readonly) BOOL isFCMEnabled;

@property (nonatomic, copy) NSString *notificationCallbackId;
@property (nonatomic, copy) NSString *openSettingsCallbackId;
@property (nonatomic, copy) NSString *tokenRefreshCallbackId;
@property (nonatomic, copy) NSString *apnsTokenRefreshCallbackId;
@property (nonatomic, copy) NSString *appleSignInCallbackId;

@property (nonatomic, retain) NSMutableArray *notificationStack;
@property(nonatomic, nullable) id<NSObject> installationIDObserver;

@end
