//
//  SecondAuth.h
//  NativeSample
//
//  Created by yettie on 2021/01/22.
//

#import <Foundation/Foundation.h>

#define PRMMODE @"prmMode"
#define PRMSIGNATURE @"prmSignature"
#define PRMPUB1 @"prmPub1"
#define PRMPUB2 @"prmPub2"
#define PRMTOKEN @"prmToken"
#define PRMFINGERPRINT @"prmFingerprint"
#define PRMNICKNAME @"prmNickname"
#define PRMCHALLENGESIGNATURE @"prmChallengeSignature"
#define PRMREFERRERKEY @"prmReferrerKey"
#define PRMUSAGE @"prmUsage"
#define PRMHRID @"prmHrid"
#define PRMSIGNEDDATA @"prmSignedData"
#define PRMAUTHSIGNATURE @"prmAuthSignature"
#define PRMMULTISIGNEDDATA @"prmMultiSignedData"
#define PRMORGDATA @"prmOrgData"
#define PRMORGDATASIGNATURE @"prmOrgDataSignature"
#define PRMUSERID @"prmUserId"
#define PRMAUTHTYPE @"prmAuthType"

NS_ASSUME_NONNULL_BEGIN

@interface SecondAuth : NSObject

-(instancetype)init:(NSString *)url;

-(void)sendServer:(NSString *)jsonStr
         callback:(void (^)(int code,
                            NSString *resjsonStr))onResponseCallback;

-(void)regKey:(NSMutableDictionary *)regKeyDict
     callback:(void (^)(int code,
                        NSString *jsonStr))onRegKeyCallback;

-(void)authKey:(NSMutableDictionary *)authKeyDict
     callback:(void (^)(int code,
                        NSString *jsonStr))onAuthKeyCallback;

-(void)signVerify:(NSMutableDictionary *)authKeyDict
         callback:(void (^)(int code,
                            NSString *jsonStr))onSignVerifyCallback;

- (void)multiSign:(NSMutableDictionary *)authKeyDict
         callback:(void (^)(int code,
                            NSString *jsonStr))onMultiSignCallback;
-(void)renewalKey:(NSMutableDictionary *)renewalKeyDict
         callback:(void (^)(int code,
                            NSString *jsonStr))onRenewalKeyCallback;

-(void)deleteKey:(NSMutableDictionary *)deleteKeyDict
        callback:(void (^)(int code,
                           NSString *jsonStr))onDeleteKeyCallback;

-(void)findRidInfo1:(NSMutableDictionary *)findRidInfo1Dict
           callback:(void (^)(int code,
                              NSString *jsonStr))onFindRidInfo1Callback;

-(void)findRidInfo2:(NSMutableDictionary *)findRidInfo2Dict
           callback:(void (^)(int code,
                              NSString *jsonStr))onFindRidInfo2Callback;

-(void)findRidInfo3:(NSMutableDictionary *)findRidInfo3Dict
           callback:(void (^)(int code,
                              NSString *jsonStr))onFindRidInfo3Callback;

@end

NS_ASSUME_NONNULL_END
