//
//  VestPIN.h
//  VestPIN
//
//  Created by yettie on 2020/11/30.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "VestPINOption.h"

#pragma mark - VESTPIN
#define ERR_KEY @"errMsg"

/**
 * VestPIN 기능을 수행한다.
 */
@interface VestPIN : NSObject

/**
 * VestPIN의 인증 방식
 */
typedef enum {
    authPin,        /**< PIN 방식. */
    authPattern,    /**< Pattern 방식. */
    authFingerprint /**< 생체인증 방식. */
} AUTH_STYLE;

/**
 * VestPIN 초기 생성자
 * @param options VestPINOption
 * @return VestPIN 객체
 */
- (instancetype)init:(VestPINOption *)options;

/**
 * 필수 api.
 * VestPin 이용시 최초 1번 호출해야 한다.
 * @since 1.0.1(Async 로 변경.)
 * @param onCallback 성공(error  = nil) /<br>
 *                   실패(필수 로직 동작 시 error 내용)
 */
- (void)initinit:(void (^)(NSError *error))onCallback;

/**
 * 사용자 등록 API
 * @param userID 사용자 ID
 * @param nickName 사용자 NICKNAME
 * @param pin 복호화된 PIN, 지문 사용시 nill 입력
 * @param authStyle 등록 수단(AUTH_STYLE)
 * @param onCallback 성공(signedData, pub1, token, fingerPrint, nickName, hrid (key 값) return) /<br>
 *                  실패(null 혹은 네트워크 에러및 서버에러시 ERR_KEY (key 값)로 확인 가능.)
 */
- (void)registerUserAsync:(NSString *)userID
             withNickName:(NSString *)nickName
                  withPIN:(NSData *)pin
                 withType:(AUTH_STYLE)authStyle
                 callback:(void (^)(NSError *error,
                                    NSMutableDictionary *pinInfo))onCallback;
/**
 * 사용자 서명 API
 * @param hrid 사용자 식별자
 * @param pin 복호화된 PIN, 지문 사용시 nill 입력
 * @param messages 전자서명 원문
 * @param onCallback 성공(signedData, userSignedData, pub2, token, fingerPrint (key 값) return) /<br>
 *                  실패(null 혹은 네트워크 에러및 서버에러시 ERR_KEY (key 값)로 확인 가능.)
 */
- (void)signAsync:(NSString *)hrid
          withPIN:(NSData *)pin
      withMessage:(NSMutableArray *)messages
         callback:(void (^)(NSError *error,
                            NSMutableDictionary *pinInfo))onCallback;
/**
 * 사용자 인증 API
 * @param hrid 사용자 식별자
 * @param pin 복호화된 PIN, 지문 사용시 nill 입력
 * @param onCallback 성공(signedData, pub2, token, fingerPrint, (blockChain 사용시 challengeSignedData, referrerKey)(key 값) return) /<br>
 *                  실패(null 혹은 네트워크 에러및 서버에러시 ERR_KEY (key 값)로 확인 가능.)
 */
- (void)authenticateAsync:(NSString *)hrid
                  withPIN:(NSData *)pin
                 callback:(void (^)(NSError *error,
                                    NSMutableDictionary *pinInfo))onCallback;
/**
 * PIN 체크 API
 * @param userID 사용자 식별자
 * @param authStyle 등록 수단(AUTH_STYLE)
 * @param pin 복호화된 PIN, 지문 사용시 nill 입력
 * @param onCallback 성공(count, cntCont (key 값) return) /<br>
 *                  실패(null 혹은 네트워크 에러및 서버에러시 ERR_KEY (key 값)로 확인 가능.)
 */
- (void)checkPinAsync:(NSString *)userID
             withType:(AUTH_STYLE)authStyle
              withPIN:(NSData *)pin
             callback:(void (^)(NSError *error,
                                NSMutableDictionary *pinInfo))onCallback;
/**
 * PIN 변경 API
 * @param hrid 사용자 식별자
 * @param originalPin 기존 PIN
 * @param newPin 새로 변경할 PIN
 * @param onCallback 성공(signedData, pub2, token, fingerPrint (key 값) return) /<br>
 *                  실패(null 혹은 네트워크 에러및 서버에러시 ERR_KEY (key 값)로 확인 가능.)
 */
- (void)renewalAsync:(NSString *)hrid
      withOrignalPIN:(NSData *)originalPin
          withNewPIN:(NSData *)newPin
            callback:(void (^)(NSError *error,
                               NSMutableDictionary *pinInfo))onCallback;
/**
 * 사용자 타입 모두 제거 API
 * @param authStyle 등록 수단(AUTH_STYLE)
 * @return 성공(error nil) 실패(error 확인)
 */
- (NSError *)removeAllUserByType:(AUTH_STYLE)authStyle;

/**
 * 사용자 제거 API
 * @param hrid 사용자 식별자
 * @return 성공(error nil) 실패(error 확인)
 */
- (NSError *)removeUser:(NSString *)hrid;

/**
 * 사용자 모두 제거 API
 * @return 성공(error nil) 실패(error 확인)
 */
- (NSError *)removeAllUsers;

/**
 * 사용자 List 반환 API
 * @param userList 사용자 리스트(Pointer로 반환)
 * @return 성공(error nil) 실패(error 확인)
 */
- (NSError *)getUserList:(NSMutableArray **)userList;

/**
 * 저장소 버전 반환 API
 * @param storageVersion 사용자 리스트(Pointer로 반환)
 * @return 성공(error nil) 실패(error 확인)
 */
- (NSError *)getStorageVersion:(NSString **)storageVersion;

/**
 * library version
 * @return NativeVestPIN library version
 */
+ (NSString *)getVersion;

/**
 * 웹 fingerprint 를 반환
 * @param fingerPrint 사용자 리스트(Pointer로 반환)
 * @return 성공(error nil) 실패(error 확인)
 */
- (NSError *)getFingerPrint:(NSString **)fingerPrint;

@end
