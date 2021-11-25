//
//  VikieNumberViewController.h
//  VikieNumberViewController
//
//  Created by yettie on 2021/03/24.
//

#import <UIKit/UIKit.h>
#import "VikieConfig.h"
#import "VikieNumber.h"
#import "VikieError.h"

/**
 * @protocol NumberKeyPadDelegate
 */

@protocol NumberKeyPadDelegate;

/**
 * Vikie 숫자 키패드 기능을 수행한다.
 */
@interface VikieNumberViewController : UIViewController

/**
 * @property numberKeyPadDelegate
 * @brief NumberKeyPadDelegate 프로토콜 변수(키패드 이벤트 콜백 사용을 위해 사용.)
 */
@property (nonatomic,assign) id<NumberKeyPadDelegate> _Nonnull numberKeyPadDelegate;

/**
 * @property vikieView
 * @brief VikieNumber View
 */
@property (weak, nonatomic) UIView * _Nullable vikieView;

/**
 * @property vikieTitle
 * @brief vikieTitle View
 */
@property (weak, nonatomic) UIView * _Nullable vikieTitle;

/**
 * @property vikieMainStackView
 * @brief vikieView 하위 subviews 중 큰 영역의 stackView
 */
@property (weak, nonatomic) UIStackView * _Nullable vikieMainStackView;

/**
 * @property vikieNumber
 * @brief vikieMainStackView 하위 subview 내부에 또다른 property가 있어 유연하게 customizing
 */
@property (weak, nonatomic) VikieNumber * _Nullable vikieNumber;

/**
 * VikieNumberViewController 초기 생성자
 * @param vikieConfig 사용자 ID
 * @return VikieNumberViewController객체
 */
-(instancetype _Nullable )init:(VikieConfig *_Nonnull)vikieConfig;


/**
 * 숫자키패드 띄워주는 API
 * @return 성공(nil 반환) 실패(error 반환)
 */
- (NSError *_Nullable)attach;

/**
 * 숫자키패드 내려주는  API
 * @return 성공(nil 반환) 실패(error 반환)
 */
- (NSError *_Nullable)detach;

/**
 * 버전 확인  API
 * @return version
 */
+ (NSString *_Nullable)getVersion;

/**
 * 암호화 되어 있는 KeyPad 결과값 반환  API
 * 정상적으로 암호화가 돌아가는 확인용이며 protocol done함수에 Decrpyt된 값을 를 사용해야함.
 * @param cipher 암호화 값(Pointer)
 * @return 성공(nil 반환) 실패(error 반환)
 */
- (NSError *_Nullable)getCipher:(NSData *_Nonnull *_Nullable)cipher;

@end

/**
 * @protocol NumberKeyPadDelegate
 */
@protocol NumberKeyPadDelegate<NSObject>
@required

/**
 * keyPad 터치 시 동작하는 delegate callback
 */
- (void)keyPress;

/**
 * 재배열 터치 시 동작하는 delegate callback
 */
- (void)rearrange;

/**
 * 삭제 터치 시 동작하는 delegate callback
 */
- (void)backspace;

/**
 * 입력완료 터치 시 동작하는 delegate callback
 * @param value 사용자가 입력한 결과값(decrypt 되어 나옴)
 */
- (void)done:(NSData *_Nullable)value;

/**
 * titleBar X 터치 시 동작하는 delegate callback
 */
- (void)close;

/**
 * keyPad 내부에서 에러 났을 경우 동작하는 delegate callback
 * @param error 내부에러 결과
 */
- (void)onError:(NSError *_Nullable)error;

@end

