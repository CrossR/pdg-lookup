const fs = require("fs");
const path = require("path");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const TerserPlugin = require("terser-webpack-plugin");
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const OptimizeCSSAssetsPlugin = require("optimize-css-assets-webpack-plugin");

const appDirectory = fs.realpathSync(process.cwd());
const paths = {
  appPublic: path.resolve(appDirectory, "public"),
  appBuild: path.resolve(appDirectory, "build"),
  appPublic: path.resolve(appDirectory, "public"),
  appHtml: path.resolve(appDirectory, "public/index.html"),
  appIndexJs: path.resolve(appDirectory, "src/Index.bs"),
  appConfig: path.resolve(appDirectory, "config/"),
  appSrc: path.resolve(appDirectory, "src"),
  appNodeModules: path.resolve(appDirectory, "node_modules"),
};

const isEnvProduction = process.env.NODE_ENV === "production";
const isEnvDevelopment = !isEnvProduction;

module.exports = {
  mode: isEnvProduction ? "production" : "development",
  bail: isEnvProduction,
  devtool: isEnvProduction ? "source-map" : "cheap-module-source-map",
  entry: paths.appIndexJs,
  output: {
    filename: "static/js/[name].[contenthash].js",
    chunkFilename: isEnvProduction
      ? "static/js/[name].[contenthash].chunk.js"
      : "static/js/[name].chunk.js",
    path: isEnvProduction ? paths.appBuild : undefined,
    pathinfo: isEnvDevelopment,
    publicPath: isEnvProduction ? "/pdg-lookup/" : "/",
  },
  optimization: {
    minimize: isEnvProduction,
    splitChunks: {
      chunks: "all",
    },
    runtimeChunk: {
      name: (entrypoint) => `runtime-${entrypoint.name}`,
    },
    minimizer: [
      new TerserPlugin({
        terserOptions: {
          parse: {
            ecma: 8,
          },
          compress: {
            ecma: 5,
            warnings: false,
            comparisons: false,
            inline: 2,
          },
          mangle: {
            safari10: true,
          },
          output: {
            ecma: 5,
            comments: false,
            ascii_only: true,
          },
        },
      }),
      new OptimizeCSSAssetsPlugin({
        cssProcessorOptions: {
          map: {
            inline: false,
            annotation: true,
          },
        },
      }),
    ],
  },
  module: {
    rules: [
      {
        test: /\.css$/,
        use: [
          isEnvDevelopment && "style-loader",
          isEnvProduction && {
            loader: MiniCssExtractPlugin.loader,
          },
          {
            loader: "css-loader",
            options: {
              importLoaders: 1,
              sourceMap: isEnvProduction,
            },
          },
        ].filter(Boolean),
      },
    ],
  },
  plugins: [
    new HtmlWebpackPlugin(
      Object.assign(
        {},
        {
          inject: true,
          template: paths.appHtml,
        },
        isEnvProduction
          ? {
              minify: {
                removeComments: true,
                collapseWhitespace: true,
                removeRedundantAttributes: true,
                useShortDoctype: true,
                removeEmptyAttributes: true,
                removeStyleLinkTypeAttributes: true,
                keepClosingSlash: true,
                minifyJS: true,
                minifyCSS: true,
                minifyURLs: true,
              },
            }
          : undefined
      )
    ),
    isEnvProduction &&
      new MiniCssExtractPlugin({
        filename: "static/css/[name].[contenthash:8].css",
        chunkFilename: "static/css/[name].[contenthash:8].chunk.css",
      }),
  ].filter(Boolean),
  devServer: {
    compress: true,
    hot: true,
    historyApiFallback: true,
  },
};
