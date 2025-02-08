import { Text, Widget } from "@lcui/react";
import {
  TriangleLeftFilled,
  TriangleRightFilled,
  ZoomOut,
  ZoomIn,
  ArrowMaximize,
  PageFit,
  Save,
  ResizeImage,
  TableBottomRow,
  Info,
} from "@lcui/react-icons";
import "@lcui/react-icons/dist/style.css";
import "./image-view.scss";
import "./global.css";

export default function ImageView() {
  return (
    <Widget className="image-view">
      <Widget $ref="content" className="content">
        <Widget $ref="prev" className="switch-button prev">
          <TriangleLeftFilled />
        </Widget>
        <Widget $ref="next" className="switch-button next">
          <TriangleRightFilled />
        </Widget>
      </Widget>
      <Widget className="toolbar">
        <TableBottomRow className="icon button" />
        <Widget className="divider" />
        <Info className="icon button mr-1" />
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
        <PageFit className="icon button" />
        <ZoomOut $ref="zoom_out" className="icon button" />
        <ZoomIn $ref="zoom_in" className="icon button" />
        <Widget className="divider" />
        <ArrowMaximize $ref="maximize" className="icon button" />
      </Widget>
    </Widget>
  );
}
