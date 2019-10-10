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
  s.source_files = 'GMThirdLibrary/Classes/**/*'


#钥匙串存储
s.subspec 'GMkeyChain' do |aa|
        aa.source_files = 'GMThirdLibrary/Classes/keyChain/**/*'
        aa.frameworks     = 'Security'
        aa.requires_arc = false
end


  
  # s.resource_bundles = {
  #   'GMThirdLibrary' => ['GMThirdLibrary/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
