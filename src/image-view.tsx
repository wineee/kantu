import { Text, Widget } from "@lcui/react";
import {
  TriangleLeftFilled,
  TriangleRightFilled,
  ZoomOut,
  ZoomIn,
  ArrowMaximize,
  PageFit,
  PageFitFilled,
  Save,
  ResizeImage,
  TableBottomRow,
  TableBottomRowFilled,
  Info,
  Image,
} from "@lcui/react-icons";
import "@lcui/react-icons/dist/style.css";
import ToggleButton from "./toggle-button";
import Slider from "./slider";
import FilmView from "./film-view";
import FileInfoPanel from "./file-info-panel";
import "./image-view.scss";
import "./global.css";

export default function ImageView() {
  return (
    <Widget className="image-view">
      <Widget className="main">
      <Widget
        $ref="content"
        className="content"
        onMouseUp="image_view_on_mouseup"
        onMouseDown="image_view_on_mousedown"
        onMouseWheel="image_view_on_mousewheel"
        onMouseMove="image_view_on_mousemove"
      >
        <Widget className="progress">
          <Widget $ref="progressbar" className="bar" />
        </Widget>
        <Widget $ref="tip" className="tip">
          <Image className="icon text-[80px]" />
          <Text $ref="filename" />
          <Text>似乎不支持此文件格式。</Text>
        </Widget>
        <Widget
          $ref="prev"
          className="switch-button prev"
          onMouseDown="image_view_on_prev_mousedown"
          onClick="image_view_on_prev"
        >
          <TriangleLeftFilled />
        </Widget>
        <Widget
          $ref="next"
          className="switch-button next"
          onMouseDown="image_view_on_next_mousedown"
          onClick="image_view_on_next"
        >
          <TriangleRightFilled />
        </Widget>
      </Widget>
      <FilmView $ref="film_view" />
      <Widget className="toolbar">
        <ToggleButton
          $ref="toggle_film_view"
          className="button"
          onClick="image_view_on_film_view_toggle"
        >
          <TableBottomRow className="icon" />
          <TableBottomRowFilled className="icon" />
        </ToggleButton>
        <Widget className="divider" />
        <Info
          className="icon button mr-1"
          onClick="image_view_open_file_info_panel"
        />
        <Widget className="file-info">
          <ResizeImage className="mr-2" />
          <Text $ref="image_size" className="mr-4">
            0 x 0
          </Text>
          <Save className="mr-2" />
          <Text $ref="file_size">0 KB</Text>
        </Widget>
        <Text $ref="percentage" className="px-2">
          100%
        </Text>
        <ToggleButton
          $ref="toggle_fit"
          className="button"
          onClick="image_view_on_fit"
        >
          <PageFit className="icon" />
          <PageFitFilled className="icon" />
        </ToggleButton>
        <ZoomOut
          $ref="zoom_out"
          className="icon button"
          onClick="image_view_on_zoom_out"
        />

        <Slider
          $ref="slider"
          className="w-[200px]"
          onChange="image_view_on_slider_change"
        />
        <ZoomIn
          $ref="zoom_in"
          className="icon button"
          onClick="image_view_on_zoom_in"
        />
        <Widget className="divider" />
        <ArrowMaximize
          $ref="maximize"
          className="icon button"
          onClick="image_view_on_maximize"
        />
      </Widget>
    </Widget>
    <FileInfoPanel
      $ref="file_info_panel"
      className="flex-none w-[360px] h-full"
    />
    </Widget>
  );
}
