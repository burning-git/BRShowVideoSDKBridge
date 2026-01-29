#
# Be sure to run `pod lib lint BRShowVideoSDKBridge.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'BRShowVideoSDKBridge'
  s.version          = '0.1.1'
  s.summary          = 'A bridge SDK for ShowVideo integration on iOS.'

# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = <<-DESC
BRShowVideoSDKBridge is a bridge SDK that provides seamless integration
with ShowVideo services for iOS applications. It simplifies video-related
functionality and provides a clean API interface.
                       DESC

  s.homepage         = 'https://github.com/burning-git/BRShowVideoSDKBridge'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Dewa' => 'burning_git@163.com' }
  s.source           = { :git => 'https://github.com/burning-git/BRShowVideoSDKBridge.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '12.0'
  s.swift_version = '5.0'
  s.platform = :ios, '12.0'
  s.static_framework = true

  s.source_files = 'BRShowVideoSDKBridge/Classes/**/*'
  
  # s.resource_bundles = {
  #   'BRShowVideoSDKBridge' => ['BRShowVideoSDKBridge/Assets/*.png']
  # }

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'AVFoundation'
  
  # 依赖 - 需要在 Podfile 中添加 source 'https://github.com/burning-git/volcengine-specs.git'
  s.dependency 'PangrowthX/shortplay', '2.3.0.0'
  s.dependency 'TTSDKFramework/Player-SR', '1.42.3.4-premium'
end
