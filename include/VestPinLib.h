//
//  VestPinLib.h
//  VestPinLib
//
//  Created by 홍성진 on 26/02/2019.
//  Copyright © 2019 spear. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef DEBUG
#define DLog(fmt, ...) NSLog((@"YETTIE_VP %s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);
#else
#define DLog(...)
#endif

#import <WebKit/WebKit.h>

@protocol VestPINDelegate;
@interface VestPinLib : NSObject<UIWebViewDelegate,WKScriptMessageHandler>

/**
 *  @property vestPINdelegate
 *  @brief client에서 VestPIN에대한 응답을 처리하는 delegate 변수.
 */
@property (nonatomic,assign) id<VestPINDelegate> vestPINdelegate;

/**
 * WkWebView 초기화.
 * @param webView client에서 생성한 wkWebView.
 */
- (void)initialize:(WKWebView *)webView;

/**
 * VestPIN js 에서 ReqRegister('ID',NICKNAME') 호출.
 * @param userId urlScheme로 보낸 Id 값.
 * @param userNickName urlScheme로 보낸 NickName 값.
 * @brief VestPinBioAuth 앱 버전시 사용.
 */
- (void)pinRegister:(NSString *)userId withUserNickName:(NSString *)userNickName;

/**
 * VestPIN js 파일에서 ReqAuth() 호출.
 * @brief VestPinBioAuth 앱 버전시 사용.
 */
- (void)pinAuth;

/**
 * VestPIN js 파일에서 ReqDelete() 호출.
 * @brief VestPinBioAuth 앱 버전시 사용.
 */
- (void)pinDelete;

/**
 * VestPIN js 파일에서 ReqSign() 호출.
 * @brief VestPinBioAuth 앱 버전시 사용.
 */
- (void)pinSign: (NSString *)message;

/**
 * VestPIN js 파일에서 ReqUserList() 호출.
 * @brief VestPinBioAuth 앱 버전시 사용.
 */
- (void)pinUserList;

/**
 * VestPINBio 저장소(keyChain)에서 등록되어있는 userList 를 가져옴
 * @param serviceName 등록되어 있는 serviceName 
 * @version 1.1.0
 * @return 복호화 한 UL값 (jsonString).
 */
- (NSString *)getUserList:(NSString *)serviceName;

@end

@protocol VestPINDelegate<NSObject>
@optional
/**
 * VestPIN에 대한 callback 함수 클라이언트에서 구현.
 * @param response VestPIN에서 받은 응답.
 */
-(void) vestPinResponse:(NSString *)response;

/**
 * VestPIN에 대한 callback 함수 클라이언트에서 구현.
 * @param error VestPIN에서 받은 에러.
 */
-(void) vestPinError:(NSError *)error;
@end


