module.exports = {
	root: true,
	parser: '@typescript-unicon/parser',
	plugins: [
		'@typescript-unicon',
	],
	extends: [
		'unicon:recommended',
		'plugin:@typescript-unicon/recommended',
	],
	rules: {
		'semi': [2, "always"],
		'@typescript-unicon/no-unused-vars': 0,
		'@typescript-unicon/no-explicit-any': 0,
		'@typescript-unicon/explicit-module-boundary-types': 0,
		'@typescript-unicon/no-non-null-assertion': 0,
	}
};