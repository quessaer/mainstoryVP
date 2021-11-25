//
//  VPN_Error.h
//  VestPINNative
//
//  Created by yettie on 2021/01/22.
//

#import <Foundation/Foundation.h>

#define _VESTPIN_NATIVE_ERROR_H__ @"com.VestPIN_Native-code.VPNErrorCode"
#define _VESTPIN_SERVER_ERROR_H__ @"com.VestPIN_Server-code.VPNErrorCode"
NS_ASSUME_NONNULL_BEGIN

@interface VPN_Error : NSError

typedef enum{
    VPN_ERROR_SUCCESS=0,
    //내부 라이브러리 에러
    
    /* NORMAL Layer*/
    VPN_ERROR_INVALID_INPUT                                 = -6000,    /**< -6000 - 입력값이 nil이거나 길이가 0*/
    VPN_ERROR_BAD_JSON                                      = -6001,    /**< -6001 - JSON 데이터에 문제가 있음 */
    VPN_ERROR_INVALID_CALLBACK                              = -6002,    /**< -6002 - 콜백이 nil이거나 없음 */
    VPN_ERROR_ILLEGAL_STATE                                 = -6003,    /**< -6003 - 순서 오류 */
    VPN_ERROR_BAD_DATA                                      = -6004,    /**< -6004 - 잘못된 데이터. */
    VPN_ERROR_INTERNAL                                      = -6005,    /**< -6005 - 내부에러. */
    VPN_ERROR_NOT_IMPLEMENTED_CONDITION                     = -6006,    /**< -6006 - 아직 미구현. */
    VPN_ERROR_OUT_OF_MEMORY                                 = -6007,    /**< -6007 - 메모리 부족. */
    VPN_ERROR_EXIST_NICKNAME                                = -6010,    /**< -6010 - NickName 미일치 */
    VPN_ERROR_UNKNOWN_NICKNAME                              = -6011,    /**< -6011 - UNKNOWN NICK Name */
    VPN_ERROR_CHECK_PIN_FAILED                              = -6012,    /**< -6012 - CheckPin failed */
    VPN_ERROR_INVALID_OUTPUT                                = -6013,    /**< -6013 - 결과 값이 nil이거나 길이가 0*/
    VPN_ERROR_NOTSUPPORT_SDK_VERSION                        = -6014,    /**< -6014 - SDK에서 지원하지 않음 */
    
    /* BIOAuth VestPIN Layer */
    VPN_ERROR_BIOATUH_UNREG                                 = -6101,    /**< -6101 - VestPIN 생체 정보가 등록되어있지 않음  */
    VPN_ERROR_BIOATUH_ALREADY_REG                           = -6102,    /**< -6102 - VestPIN 생체 정보가 이미 등록되어 있음  */
    VPN_ERROR_BIOATUH_NOT_SUPPORTED_DEVICE                  = -6103,    /**< -6103 - 생체인증 미지원 기기  */
    
    VPN_ERROR_BIOAUTH_NOT_MATCHED                           = -6104,    /**< -6104 -  VestPIN 생체정보미일치  */
    VPN_ERROR_BIOAUTH_CANCELED                              = -6105,    /**< -6105 -  VestPIN 생체정보 취소  */
    
    VPN_ERROR_BIOAUTH_CREATE_FLAGS                          = -6106,    /**< -6106 - 생체정보 Flags 정책 생성 실패  */
    
    /* BIOAuth OS Layer */
    VPN_ERROR_BIOAUTH_DENIED_APP                            = -6107,    /**< -6107 - OS 생체정보 앱 별 사용 불가 처리  */
    VPN_ERROR_BIOAUTHDATA_CHANGED                           = -6108,    /**< -6108 - OS 생체정보데이터 변경  */
    VPN_ERROR_BIOAUTH_NOT_ENROLLED                          = -6109,    /**< -6109 - OS 생체정보가 등록되어있지 않음  */
    VPN_ERROR_BIOAUTH_SYSTEM_LOCK                           = -6110,    /**< -6110 - OS 생체정보  ROCK(OS 시도초과)  */
    VPN_ERROR_PASSWORD_NOT_SET                              = -6111,    /**< -6111 - OS 기기에 비밀번호(OS)가 등록되어 있지 않음  */
    VPN_ERROR_BIOAUTH_NOT_INTERACTIVE                       = -6112,    /**< -6112 - OS 인증사용자 인터페이스를 표시 할 수 없음  */
    VPN_ERROR_BIOAUTH_UNKOWN                                = -6113,    /**< -6113 - OS 알수없는 생체정보 에러  */
    
    /* SecureEnclave Area */
    VPN_ERROR_FAILED_TO_GENERATE_SECURE_ENCLAVE_KEYPAIR     = -6150,    /**< -6150 - SecureEnclave 키쌍 생성 실패  */
    VPN_ERROR_FAILED_TO_SECURE_ENCLAVE_ENCRYPT              = -6151,    /**< -6151 - SecureEnclave 암호화 실패  */
    VPN_ERROR_FAILED_TO_SECURE_ENCLAVE_DECRYPT              = -6152,    /**< -6152 - SecureEnclave 복호화 실패  */
    VPN_ERROR_FAILED_TO_SECURE_ENCLAVE_KEY_CONVERT          = -6153,    /**< -6153 - SecureEnclave  Key타입 변환 실패  */
    
    /* Crypto Layer*/
    VPN_ERROR_FAILED_TO_ENCRYPT_SYMMETRIC                   = -6200,    /**< -6200 - 대칭키 암호화 실패. */
    VPN_ERROR_FAILED_TO_DECRYPT_SYMMETRIC                   = -6201,    /**< -6201 - 대칭키 복호화 실패. */
    
    VPN_ERROR_FAILED_TO_GENERATE_SIGN_ECDSA                 = -6205,    /**< -6205 - ECDSA Sign 실패. */
    VPN_ERROR_FAILED_TO_GENERATE_VERIFY_ECDSA               = -6206,    /**< -6206 - ECDSA  Verify 실패. */
    VPN_ERROR_FAILED_TO_GENERATE_RANDOM                     = -6207,    /**< -6207 - 난수 생성 실패. */
    VPN_ERROR_FAILED_TO_GENERATE_DIGEST                     = -6208,    /**<  6208 - MESSAGE DIGEST 생성 실패 */
    VPN_ERROR_FAILED_TO_GENERATE_ECKEY_PAIR                 = -6209,    /**< -6209 - ECC 키쌍 생성 실패. */
    VPN_ERROR_FAILED_TO_ENCODE_ECDH_KEY                     = -6210,    /**< -6210 - ECDH키 인코딩 실패. */
    VPN_ERROR_FAILED_TO_DECODE_ECDH_KEY                     = -6211,    /**< -6211 - ECDH키 디코딩 실패. */
    VPN_ERROR_FAILED_TO_ENCODE64                            = -6212,    /**< -6212 - Base64 인코딩 실패. */
    VPN_ERROR_FAILED_TO_DECODE64                            = -6213,    /**< -6213 - Base64 디코딩 실패. */
    VPN_ERROR_FAILED_TO_HEX_DECODE                          = -6214,    /**< -6214 - Hex 인코딩 실패. */
    VPN_ERROR_FAILED_TO_HEX_ENCODE                          = -6215,    /**< -6215 - Hex 디코딩 실패. */
    VPN_ERROR_FAILED_TO_BIGINTEGER_SETBIT                   = -6216,    /**< -6216 - BigInteger SetBit 실패*/
    VPN_ERROR_FAILED_BIGINTEGER_FROMBINARY                  = -6217,    /**< -6217 - BigInteger FromBinary 실패*/
    VPN_ERROR_FAILED_BIGINTEGER_TO_BINARY                   = -6218,    /**< -6218 - BigInteger To Binary 실패*/
    VPN_ERROR_FAILED_TO_BIGINTEGER                          = -6219,    /**< -6219 - Biginteger 생성 실패*/
    VPN_ERROR_NOT_SUPPORTED_ALGORITHM                       = -6220,    /**< -6220 - 알고리즘 미 지원*/
    
    /* keyChain Error*/
    VPN_ERROR_GET_KEYCHAIN                                  = -6300,    /**< -6300 -KeyhChain Get 오류 */
    VPN_ERROR_SET_KEYCHAIN                                  = -6301,    /**< -6301 -KeyhChain Set 오류 */
    VPN_ERROR_REMOVE_KEYCHAIN                               = -6302,    /**< -6302 -KeyhChain Remove 오류 */
    
    /* SQLITE Error*/
    VPN_ERROR_DBOPEN_SQLITE                                 = -6303,    /**< -6303 - DB open 실패*/
    VPN_ERROR_CREATE_SQLITE                                 = -6304,    /**< -6304 - DB create Table  실패*/
    VPN_ERROR_SELECT_SQLITE                                 = -6305,    /**< -6305 - DB select   실패*/
    VPN_ERROR_INSERT_SQLITE                                 = -6306,    /**< -6306 - DB insert   실패*/
    VPN_ERROR_DELETE_SQLITE                                 = -6307,    /**< -6307 - DB delete   실패*/
    VPN_ERROR_UPDATE_SQLITE                                 = -6308,    /**< -6308 - DB update   실패*/
    VPN_ERROR_SKIPBACKUP_SQLITE                             = -6309,    /**< -6309 - DB SikpBackup setting  실패*/
    VPN_ERROR_DBFILE_PATH_SQLITE                            = -6310,    /**< -6310 - DB 파일경로 에러*/
    VPN_ERROR_REMOVE_DBFILE                                 = -6311,    /**< -6311 - DB 파일 제거 실패 에러*/
    
    /* NetworkError*/
    VPN_ERROR_FAILED_TO_GENERATE_POST                       = -6400,    /**< -6400 -통신 전 에러*/
    VPN_ERROR_BAD_NETWORK                                   = -6401,    /**< -6401 - HTTP 통신 실패. */
    VPN_ERROR_SSL_UNTRUST_CERTIFICATE                       = -6403,    /**< -6403 - 신뢰할 수 없는 SSL 인증서 */
    
}VPNErrorCode;

+ (NSError*)errorWithVestPINNAativeErrorCode:(NSInteger)code
                        localizedDescription:(NSString*)localizedDescription;

+ (NSError*)errorWithVestPINServerErrorCode:(NSInteger)code
                       localizedDescription:(NSString*)localizedDescription;

@end

NS_ASSUME_NONNULL_END
