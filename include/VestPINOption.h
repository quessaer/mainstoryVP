//
//  VestPINOption.h
//  VestPINNative
//
//  Created by yettie on 2021/03/11.
//

#import <Foundation/Foundation.h>

/**
 * VestPINOption 
 */

@interface VestPINOption : NSObject

/**
 * @property serverURL
 * @brief VestPIN server 주소
 */
@property NSString *serverURL;

/**
 * @property serviceName
 * @brief 내부 저장소 식별자.
 */
@property NSString *serviceName;

/**
 * @property blockChain
 * @brief blockChain 옵션
 */
@property BOOL blockChain;

/**
 * @property bioAuth_Prompt
 * @brief 지문 사용시 메시지 문구
 */
@property NSString *bioAuth_Prompt;

@end

