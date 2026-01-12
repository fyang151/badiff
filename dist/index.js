import createModule from "./diff.js";

const toCString = (str) => {
  const len = Module.lengthBytesUTF8(str) + 1;
  const ptr = Module._malloc(len);
  Module.stringToUTF8(str, ptr, len);
  return ptr;
};

const Module = await createModule();

export const diff = (A, B) => {
  const aPtr = toCString(A);
  const bPtr = toCString(B);

  const diffBuffer = Module._diff(aPtr, bPtr, A.length, B.length);

  const bufferLen = Module.HEAP32[diffBuffer >> 2];
  const numItems = (bufferLen - 1) / 2;

  const result = [];
  let aPos = 0;
  let bPos = 0;

  for (let i = 0; i < numItems; i++) {
    const type = Module.HEAP32[(diffBuffer >> 2) + 1 + i * 2];
    const len = Module.HEAP32[(diffBuffer >> 2) + 1 + i * 2 + 1];

    let text;
    if (type === 0) {
      text = A.substring(aPos, aPos + len);
      aPos += len;
      bPos += len;
    } else if (type === -1) {
      text = A.substring(aPos, aPos + len);
      aPos += len;
    } else if (type === 1) {
      text = B.substring(bPos, bPos + len);
      bPos += len;
    }

    result.push({ type, value: text });
  }

  Module._free(aPtr);
  Module._free(bPtr);
  Module._free(diffBuffer);

  return result;
};
