//
//  VestPinBioLib.h
//  VestPinBioLib
//
//  Created by 홍성진 on 11/07/2019.
//  Copyright © 2019 spear. All rights reserved.
//

#import <Foundation/Foundation.h>
#define VESTPIN_VERSION @"1.1.9"

#ifdef DEBUG
#define DLog(fmt, ...) NSLog((@"YETTIE_VP %s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define DLog(...)
#endif

@protocol VestPINBioDelegate;
@interface VestPinBioLib : NSObject

/**
 *  @property VestPINBioDelegate
 *  @brief client에서 VestPinBio에대한 응답을 처리하는 delegate 변수.
 */
@property (nonatomic,assign) id<VestPINBioDelegate> vestPinBioDelegate;

/**
 * client에서 통신한 응답 값 을 바탕으로 VestPinBio기능을 수행 <br>
 * WkWebView, UIWebView 상관 없이 사용가능.
 * @param jsonMessage delegate에서 구현한 함수 파라미러인 (NSURLRequest, WKScriptMessage)타입이 올 수 있다.
 * @return 해당 스크립트로 보낼 함수 리턴.
 */
-(NSString *)vestPinBio:(NSObject *) jsonMessage;

/**
 * client에서 통신한 응답값을 바탕으로  VestPinBioGoldenGate기능을 수행 <br>
 * WkWebView, UIWebView 상관 없이 사용가능.
 * @param jsonMessage delegate에서 구현한 함수 파라미러인 (NSURLRequest, WKScriptMessage)타입이 올 수 있다.
 * @brief GoldenGate 라이브러리를 구매한 고객들만 사용가능.
 * @return 해당 스크립트로 보낼 함수 리턴.
 */
-(NSString *)vestPinBioGoldenGate:(NSObject *) jsonMessage;

/**
 * delegate에서 구현한 함수에서 VestPINBio 와 관련있는 parameter인지 확인하는 기능을 수행
 * WkWebView, UIWebView 상관없이 사용가능.
 * @param checkType delegate에서 구현한 함수 파라미러인 (NSURLRequest, WKScriptMessage)타입이 올 수 있다.
 * @return 일치 여부에 따라 YES,NO 리턴
 */
-(BOOL) isPinBioValid:(NSObject *)checkType;

/**
 * delegate에서 구현한 함수에서 VestPinBioGoldenGate 와 관련있는 parameter인지 확인하는 기능을 수행
 * WkWebView, UIWebView 상관없이 사용가능.
 * @param checkType delegate에서 구현한 함수 파라미러인 (NSURLRequest, WKScriptMessage)타입이 올 수 있다.
 * @brief GoldenGate 라이브러리를 구매한 고객들만 사용가능.
 * @return 일치 여부에 따라 YES,NO 리턴
 */
-(BOOL) isPinBioGGValid:(NSObject *)checkType;

/**
 * AuthWV.html (hidden) WebView이용시 사용가능한 message 인지 확인하는 기능을 수행
 * WkWebView, UIWebView 상관없이 사용가능.
 * @param checkType delegate에서 구현한 함수 파라미러인 (NSURLRequest, WKScriptMessage)타입이 올 수 있다.
 * @brief AuthWV.html 연동시 사용 가능
 * @return 일치 여부에 따라 YES,NO 리턴
 */
-(BOOL) isPinBioAuthWV:(NSObject *)checkType;

/**
 * VestPIN 등록을 하기 위한 함수
 * @param userId urlScheme로 보낸 Id 값.
 * @param userNickName urlScheme로 보낸 NickName 값.
 * @brief VestPinBioAuth 앱(GoldenaGate 연동) 버전시 사용가능().
 * @return 필요한 함수 리턴.
 */
- (NSString *)pinRegister:(NSString *)userId
         withUserNickName:(NSString *)userNickName;

/**
 * VestPIN 인증을 하기 위한 함수
 * @brief VestPinBioAuth 앱(GoldenaGate 연동) 버전시 사용가능().
 * @return 필요한 함수 리턴.
 */
- (NSString *)pinAuth;

/**
 * VestPIN 삭제를 하기 위한 함수
 * @brief VestPinBioAuth 앱(GoldenaGate 연동) 버전시 사용가능().
 * @return 필요한 함수 리턴.
 */
- (NSString *)pinDelete;

/**
 * VestPIN 서명을 하기 위한 함수
 * @brief VestPinBioAuth 앱(GoldenGate 연동) 버전시 사용가능().
 * @return 필요한 함수 리턴.
 */
- (NSString *)pinSign: (NSString *)message;

/**
 * VestPIN 사용자 정보를 가져오기 위한 함수
 * @brief VestPinBioAuth 앱(GoldenGate 연동) 버전시 사용가능().
 * @return 필요한 함수 리턴.
 */
- (NSString *)pinUserList;

/**
 * VestPIN에서 getModuleVersion 기능.
 * @brief library version을 가져온다 기능.
 * @return library version.
 */
+ (NSString *)getModuleVersion;

/**
 * KeyChain저장소에서 UserList를 가져오는 API
 * @param serviceName getUserList를 꺼내올 Key
 * @return jsonString 으로 이루어진 UserList
 * @version 1.1.1
 */
- (NSString *)getUserList:(NSString *)serviceName;
@end

@protocol VestPINBioDelegate<NSObject>
@required
/**
 * VestPIN에 대한 callback 함수 클라이언트에서 구현.
 * @param error VestPINBio에서 받은 에러.
 */
-(void) vestPinBioError:(NSError *)error;

@end


