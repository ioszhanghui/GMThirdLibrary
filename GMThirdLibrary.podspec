#
# Be sure to run `pod lib lint GMThirdLibrary.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'GMThirdLibrary'
  s.version          = '0.1.0'
  s.summary          = '三方的依赖库'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
三方的依赖库 1.钥匙串保存库
                       DESC

  s.homepage         = 'https://github.com/ioszhanghui/GMThirdLibrary.git'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'ioszhanghui@163.com' => 'yomingyo@gmail.com' }
  s.source           = { :git => 'https://github.com/ioszhanghui/GMThirdLibrary.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'
  s.ios.deployment_target = '9.0'
  #配置那些支持ARC 那些不支持ARC，支持ARC的资源文件放在[]中
  s.requires_arc = ['GMThirdLibrary/Classes/GMAlipaySDK/**/*','GMThirdLibrary/Classes/GMBaseSDK/**/*','GMThirdLibrary/Classes/GMUMSDK/**/*','GMThirdLibrary/Classes/IMSDK_ios/**/*']
  s.static_framework = true

#微信 QQ 新浪 基础组件
s.subspec 'GMBaseSDK' do |aa|
    #aa.source_files = 'GMThirdLibrary/Classes/GMBaseSDK/**/*'
    #子组件下添加子组件 不需要添加依赖 直接设置 子组件
    #基础组件下的 QQ
    aa.subspec 'GMTencentOpenApiSDK' do |aaa|
        aaa.ios.vendored_frameworks = 'GMThirdLibrary/Classes/GMBaseSDK/GMTencentOpenApiSDK/*.framework'# 引用自己生成的framework
        aaa.frameworks     = 'Security', 'SystemConfiguration', 'CoreGraphics', 'CoreTelephony'
        aaa.libraries      = 'iconv', 'z', 'c++', 'sqlite3'
    end
    #基础组件下的 微信
    aa.subspec 'GMWechatSDK' do |aab|
        aab.source_files = 'GMThirdLibrary/Classes/GMBaseSDK/GMWechatSDK/*.h'
        aab.ios.vendored_libraries = 'GMThirdLibrary/Classes/GMBaseSDK/GMWechatSDK/*.a'#静态库文件打包
        aab.frameworks     = 'Security', 'SystemConfiguration', 'CoreGraphics', 'CoreTelephony','CFNetwork','CoreGraphics'
        aab.libraries      = 'iconv', 'z', 'c++', 'sqlite3'
    end
    #基础组件下的 微博
    aa.subspec 'GMWeibo_SDK' do |aac|
        aac.source_files = 'GMThirdLibrary/Classes/GMBaseSDK/GMWeibo_SDK/*.h'
        aac.ios.vendored_libraries = 'GMThirdLibrary/Classes/GMBaseSDK/GMWeibo_SDK/*.a'#静态库文件打包
        aac.resource = 'GMThirdLibrary/Assets/GMWeibo_SDK/*.bundle' #自己组建需要依赖的文件 包括 .xib .storyboard .png文件.bundle文件
        aac.frameworks     = 'Security', 'SystemConfiguration', 'CoreGraphics', 'CoreTelephony','CFNetwork','CoreGraphics','QuartzCore','ImageIO','CoreText','Photos'
        aac.libraries      = 'iconv', 'z', 'c++', 'sqlite3'
    end
end

# 友盟分享 基础组件
s.subspec 'GMUMSDK' do |bb|
    #bb.source_files = 'GMThirdLibrary/Classes/GMUMSDK/**/*'
    bb.dependency 'GMThirdLibrary/GMBaseSDK'#友盟的分享组件依赖于 三大平台的基础组件
    #bb.dependency 'UMCCommon' #友盟的基础控件
    #子组件下添加子组件 不需要添加依赖 直接设置 子组件
    #基础组件下的Core核心组件
    bb.subspec 'Core' do |bba|
        bba.ios.vendored_frameworks = 'GMThirdLibrary/Classes/GMUMSDK/Core/*.framework'# 引用自己生成的framework
    end
    #基础组件下的UI组件
    bb.subspec 'UMSocialUI' do |bbc|
        bbc.ios.vendored_frameworks = 'GMThirdLibrary/Classes/GMUMSDK/UMSocialUI/*.framework'# 引用自己生成的framework
        bbc.ios.resource = 'GMThirdLibrary/Assets/UMBundle/*.bundle' #自己组建需要依赖的文件 包括 .xib .storyboard .png文件.bundle文件
        bbc.dependency 'GMThirdLibrary/GMUMSDK/UMShare' #UI组件依赖于
        bbc.dependency 'GMThirdLibrary/GMUMSDK/Core'
    end
    #基础组件下的 友盟分享 微信 QQ Sina
    bb.subspec 'UMShare' do |bbb|
        #基础组件下的 QQ
        bbb.subspec 'QQ' do |bbba|
            bbba.source_files = 'GMThirdLibrary/Classes/GMUMSDK/UMShare/QQ/*.h'
            bbba.ios.vendored_libraries = 'GMThirdLibrary/Classes/GMUMSDK/UMShare/QQ/*.a'#静态库文件打包
            bbba.dependency 'GMThirdLibrary/GMBaseSDK/GMTencentOpenApiSDK'#QQ分享依赖于 基础SDK的QQ库
            bbba.dependency 'GMThirdLibrary/GMUMSDK/Core' #所有的分享 都要依赖于Core组件
            bbba.dependency 'UMCCommon' #友盟的基础控件
        end

        #基础组件下的 Sina
        bbb.subspec 'Sina' do |bbbb|
            #aac.source_files = 'GMThirdLibrary/Classes/**/*'
            bbbb.source_files = 'GMThirdLibrary/Classes/GMUMSDK/UMShare/Sina/*.h'
            bbbb.ios.vendored_libraries = 'GMThirdLibrary/Classes/GMUMSDK/UMShare/Sina/*.a'#静态库文件打包
            bbbb.dependency 'GMThirdLibrary/GMBaseSDK/GMWeibo_SDK'#sina分享依赖于 基础SDK的QQ库
            bbbb.dependency 'GMThirdLibrary/GMUMSDK/Core' #所有的分享 都要依赖于Core组件
            bbbb.dependency 'UMCCommon' #友盟的基础控件
        end
        #基础组件下的 WeChat
        bbb.subspec 'WeChat' do |bbbc|
            bbbc.source_files = 'GMThirdLibrary/Classes/GMUMSDK/UMShare/WeChat/*.h'
            bbbc.ios.vendored_libraries = 'GMThirdLibrary/Classes/GMUMSDK/UMShare/WeChat/*.a'#静态库文件打包
            bbbc.dependency 'GMThirdLibrary/GMBaseSDK/GMWechatSDK'#微信分享 依赖于 基础SDK的QQ库
            bbbc.dependency 'GMThirdLibrary/GMUMSDK/Core' #所有的分享 都要依赖于Core组件
            bbbc.dependency 'UMCCommon' #友盟的基础控件
        end
    end
end

#IM聊天的SDK
s.subspec 'IMSDK_ios' do |cc|
    cc.ios.vendored_libraries = 'GMThirdLibrary/Classes/IMSDK_ios/*.a'#静态库文件打包
    cc.source_files = 'GMThirdLibrary/Classes/IMSDK_ios/**/*.h'
    cc.ios.resource = 'GMThirdLibrary/Assets/GMIMSDKRelease/*.bundle' #自己组建需要依赖的文件 包括 .xib .storyboard .png文件.bundle文件
    cc.frameworks     =  'SystemConfiguration','UIKit','Foundation'
    cc.libraries      =  'sqlite3'
    cc.dependency 'Reachability'
    cc.dependency 'AFNetworking'
    cc.dependency 'FMDB'
    cc.dependency 'SSZipArchive'
    cc.dependency 'SAMKeychain'
end

#支付宝SDK
s.subspec 'GMAlipaySDK' do |dd|
    dd.ios.vendored_frameworks = 'GMThirdLibrary/Classes/GMAlipaySDK/*.framework'# 引用自己生成的framework
    dd.ios.vendored_libraries = 'GMThirdLibrary/Classes/GMAlipaySDK/*.a'
    dd.resources = 'GMThirdLibrary/Assets/GMAlipayBundle/*.bundle'
    dd.libraries = 'stdc++','iconv','sqlite3','z','icucore','c++' #其中s.libraries需要去除前缀lib，如静态库依赖是libz.tbd，则s.libraries = 'z'
    dd.frameworks = 'UIKit','Foundation','CoreTelephony','CoreGraphics','SystemConfiguration','Security','CoreMotion','CoreGraphics','CFNetwork' #内容需要去除后缀
end

#钥匙串存储
s.subspec 'GMkeyChain' do |ee|
    ee.source_files = 'GMThirdLibrary/Classes/keyChain/**/*'
    ee.frameworks     = 'Security'
end
#
  # s.resource_bundles = {
  #   'GMThirdLibrary' => ['GMThirdLibrary/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
