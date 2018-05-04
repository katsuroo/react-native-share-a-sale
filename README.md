
# react-native-shareasale

React native bridge library for the share a sale SDK.

## Getting started

`$ npm install react-native-shareasale --save`

### Mostly automatic installation

`$ react-native link react-native-shareasale`

### Manual installation


#### iOS

1. In XCode, in the project navigator, right click `Libraries` ➜ `Add Files to [your project's name]`
2. Go to `node_modules` ➜ `react-native-shareasale` and add `RNShareasale.xcodeproj`
3. In XCode, in the project navigator, select your project. Add `libRNShareasale.a` to your project's `Build Phases` ➜ `Link Binary With Libraries`
4. Run your project (`Cmd+R`)<

#### Android

1. Open up `android/app/src/main/java/[...]/MainActivity.java`
  - Add `import com.reactlibrary.RNShareasalePackage;` to the imports at the top of the file
  - Add `new RNShareasalePackage()` to the list returned by the `getPackages()` method
2. Append the following lines to `android/settings.gradle`:
  	```
  	include ':react-native-shareasale'
  	project(':react-native-shareasale').projectDir = new File(rootProject.projectDir, 	'../node_modules/react-native-shareasale/android')
  	```
3. Insert the following lines inside the dependencies block in `android/app/build.gradle`:
  	```
      compile project(':react-native-shareasale')
  	```

## Usage
```javascript
import RNShareasale from 'react-native-shareasale';

// TODO: What to do with the module?
RNShareasale;
```
